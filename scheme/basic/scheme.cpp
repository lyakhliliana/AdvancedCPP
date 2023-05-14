#include "scheme.h"
#include <sstream>
Interpreter::Interpreter() {
    functions_["number?"] = std::make_shared<IsNumber>(IsNumber{});
    functions_["boolean?"] = std::make_shared<IsBool>(IsBool{});
    functions_["="] = std::make_shared<Equal>(Equal{});
    functions_[">"] = std::make_shared<Greater>(Greater{});
    functions_[">="] = std::make_shared<GreaterEqual>(GreaterEqual{});
    functions_["<"] = std::make_shared<Less>(Less{});
    functions_["<="] = std::make_shared<LessEqual>(LessEqual{});
    functions_["+"] = std::make_shared<Plus>(Plus{});
    functions_["-"] = std::make_shared<Minus>(Minus{});
    functions_["*"] = std::make_shared<Multiply>(Multiply{});
    functions_["/"] = std::make_shared<Divide>(Divide{});
    functions_["max"] = std::make_shared<Max>(Max{});
    functions_["min"] = std::make_shared<Min>(Min{});
    functions_["abs"] = std::make_shared<Abs>(Abs{});
    functions_["quote"] = std::make_shared<Quote>(Quote{});
    functions_["not"] = std::make_shared<Not>(Not{});
    functions_["or"] = std::make_shared<Or>(Or{});
    functions_["and"] = std::make_shared<And>(And{});
    functions_["pair?"] = std::make_shared<IsPair>(IsPair{});
    functions_["list?"] = std::make_shared<IsList>(IsList{});
    functions_["null?"] = std::make_shared<IsNull>(IsNull{});
    functions_["cons"] = std::make_shared<Cons>(Cons{});
    functions_["car"] = std::make_shared<Car>(Car{});
    functions_["cdr"] = std::make_shared<Cdr>(Cdr{});
    functions_["list"] = std::make_shared<List>(List{});
    functions_["list-ref"] = std::make_shared<ListRef>(ListRef{});
    functions_["list-tail"] = std::make_shared<ListTail>(ListTail{});
}

std::string Interpreter::Run(const std::string &string) {
    std::stringstream stream{string};
    Tokenizer tokenizer{&stream};
    auto head = Read(&tokenizer);
    if (!tokenizer.IsEnd()) {
        throw SyntaxError("");
    }
    if (!head) {
        throw RuntimeError("");
    }
    if (Is<Bool>(head)) {
        return As<Bool>(head)->MakeString();
    } else if (Is<Number>(head)) {
        return As<Number>(head)->MakeString();
    } else if (Is<Symbol>(head)) {
        if (!functions_.contains(As<Symbol>(head)->GetName())) {
            throw NameError("wrong func name");
        }
        throw RuntimeError("no arguments for func");
    } else {
        return Calc(As<Cell>(head));
    }
}
std::string Interpreter::Calc(std::shared_ptr<Cell> obj, bool flag) {
    if (!obj->GetFirst() || !Is<Symbol>(obj->GetFirst())) {
        throw RuntimeError("");
    }
    if (!functions_.contains(As<Symbol>(obj->GetFirst())->GetName())) {
        if (flag) {
            return "";
        }
        throw NameError("wrong func name");
    }
    if (As<Symbol>(obj->GetFirst())->GetName() == "and" ||
        As<Symbol>(obj->GetFirst())->GetName() == "or") {
        flag = true;
    }
    auto func = functions_[As<Symbol>(obj->GetFirst())->GetName()];
    std::vector<std::shared_ptr<Object>> args;
    if (As<Symbol>(obj->GetFirst())->GetName() == "quote") {
        args.push_back(As<Cell>(obj->GetSecond())->GetFirst());
        return func->Apply(args);
    }
    MakeArgs(args, obj->GetSecond(), flag);
    if (args.size() > 1 && !args.back()) {
        args.pop_back();
    }
    return func->Apply(args);
}

void Interpreter::MakeArgs(std::vector<std::shared_ptr<Object>> &args,
                           std::shared_ptr<Object> object, bool flag) {
    if (!object) {
        return;
    }
    if (!Is<Cell>(object)) {
        args.push_back(object);
        return;
    }
    if (!As<Cell>(object)->GetFirst()) {
        args.push_back(nullptr);
        return;
    }
    if (!Is<Cell>(As<Cell>(object)->GetFirst())) {
        args.push_back(As<Cell>(object)->GetFirst());
    } else {
        auto temp = As<Cell>(As<Cell>(object)->GetFirst());
        if (temp->GetFirst() && Is<Symbol>(temp->GetFirst())) {
            auto answer = Calc(temp, flag);
            if (answer == "#t" || answer == "#f") {
                args.push_back(std::make_shared<Bool>(Bool{answer == "#t"}));
            } else if (answer[0] == '-' || std::isdigit(answer[0])) {
                args.push_back(std::make_shared<Number>(Number{std::stoi(answer)}));
            } else {
                args.push_back(std::make_shared<Symbol>(Symbol{answer}));
            }
        } else {
            MakeArgs(args, temp, flag);
        }
    }
    if (!As<Cell>(object)->GetSecond()) {
        return;
    }
    if (!Is<Cell>(As<Cell>(object)->GetSecond())) {
        args.push_back(As<Cell>(object)->GetSecond());
    } else {
        auto temp = As<Cell>(As<Cell>(object)->GetSecond());
        if (temp->GetFirst() && Is<Symbol>(temp->GetFirst())) {
            auto answer = Calc(temp, flag);
            if (answer == "#t" || answer == "#f") {
                args.push_back(std::make_shared<Bool>(Bool{answer == "#t"}));
            } else if (answer[0] == '-' || std::isdigit(answer[0])) {
                args.push_back(std::make_shared<Number>(Number{std::stoi(answer)}));
            } else {
                args.push_back(std::make_shared<Symbol>(Symbol{answer}));
            }
        } else {
            MakeArgs(args, temp, flag);
        }
    }
}