#include "parser.h"
#include "error.h"

void IsEnd(Tokenizer* tokenizer) {
    if (tokenizer->IsEnd()) {
        throw SyntaxError("End");
    }
}

std::shared_ptr<Object> Read(Tokenizer* tokenizer) {
    IsEnd(tokenizer);
    auto token = tokenizer->GetToken();
    tokenizer->Next();

    if (BooleanToken* bool_value = std::get_if<BooleanToken>(&token)) {
        if (*bool_value == BooleanToken::TRUE) {
            return std::make_shared<Bool>(true);
        } else {
            return std::make_shared<Bool>(false);
        }
    }
    if (BracketToken* bracket = std::get_if<BracketToken>(&token)) {
        if (*bracket == BracketToken::OPEN) {
            return ReadList(tokenizer);
        } else {
            return std::make_shared<Symbol>(")");
        }
    }
    if (ConstantToken* num = std::get_if<ConstantToken>(&token)) {
        return std::make_shared<Number>(num->value);
    } else if (SymbolToken* symbol = std::get_if<SymbolToken>(&token)) {
        return std::make_shared<Symbol>(symbol->name);
    } else if (std::get_if<QuoteToken>(&token)) {
        if (tokenizer->IsEnd()) {
            throw SyntaxError("");
        }
        std::queue<std::shared_ptr<Object>> objects;
        objects.push(std::make_shared<Symbol>("quote"));
        objects.push(Read(tokenizer));
        return ForCell(objects);
    } else if (std::get_if<DotToken>(&token)) {
        return std::make_shared<Symbol>(".");
    }
    return nullptr;
}

std::shared_ptr<Object> ReadList(Tokenizer* tokenizer) {
    IsEnd(tokenizer);
    std::queue<std::shared_ptr<Object>> vec;
    auto cur = Read(tokenizer);
    while (!(Is<Symbol>(cur) && As<Symbol>(cur)->GetName() == ")")) {
        vec.push(cur);
        IsEnd(tokenizer);
        cur = Read(tokenizer);
    }
    return ForCell(vec);
}

std::shared_ptr<Object> ForCell(std::queue<std::shared_ptr<Object>>& vec) {
    if (vec.empty()) {
        return nullptr;
    }
    std::shared_ptr<Object> fir = vec.front(), sec;
    if (Is<Symbol>(fir) && As<Symbol>(fir)->GetName() == ".") {
        throw SyntaxError("");
    }
    vec.pop();
    if (vec.empty()) {
        sec = nullptr;
    } else if (Is<Symbol>(vec.front()) && As<Symbol>(vec.front())->GetName() == ".") {
        if (vec.size() == 2) {
            vec.pop();
            sec = vec.front();
            vec.pop();
        } else {
            throw SyntaxError("");
        }
    } else {
        sec = ForCell(vec);
    }
    return std::make_shared<Cell>(fir, sec);
}