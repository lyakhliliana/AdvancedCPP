#pragma once

#include "error.h"
#include <memory>
#include <string>
#include <vector>

class Object : public std::enable_shared_from_this<Object> {
public:
    virtual ~Object() = default;
    virtual std::string MakeString() = 0;
};

class Number : public Object {
public:
    Number(int val) : value_(val) {
    }
    int GetValue() const {
        return value_;
    }
    std::string MakeString() override {
        return std::to_string(value_);
    }

private:
    int value_;
};

class Symbol : public Object {
public:
    Symbol(const std::string& name) : name_(name) {
    }
    const std::string& GetName() const {
        return name_;
    }
    std::string MakeString() override {
        return GetName();
    }

private:
    std::string name_;
};

class Cell : public Object {
public:
    Cell(std::shared_ptr<Object> first, std::shared_ptr<Object> second)
        : first_(first), second_(second) {
    }
    std::shared_ptr<Object> GetFirst() const {
        return first_;
    }
    std::shared_ptr<Object> GetSecond() const {
        return second_;
    }
    std::string MakeString() override {
        std::string result;
        if (first_) {
            result += first_->MakeString();
        }
        if (second_) {
            result += second_->MakeString();
        }
        return result;
    }

private:
    std::shared_ptr<Object> first_;
    std::shared_ptr<Object> second_;
};

class Bool : public Object {
public:
    Bool(bool value) : bool_(value) {
    }
    bool GetValue() const {
        return bool_;
    }
    std::string MakeString() override {
        return (bool_) ? "#t" : "#f";
    }

private:
    bool bool_;
};

///////////////////////////////////////////////////////////////////////////////

// Runtime type checking and convertion.
// This can be helpful: https://en.cppreference.com/w/cpp/memory/shared_ptr/pointer_cast

template <class T>
std::shared_ptr<T> As(const std::shared_ptr<Object>& obj) {
    return std::dynamic_pointer_cast<T>(obj);
}

template <class T>
bool Is(const std::shared_ptr<Object>& obj) {
    return std::dynamic_pointer_cast<T>(obj) != nullptr;
}

////////////////////////////////////////////////////////////////////////////////

class Function {
public:
    virtual ~Function() = default;
    virtual std::string Apply(const std::vector<std::shared_ptr<Object>>& args) = 0;
};
class IsNumber : public Function {
public:
    std::string Apply(const std::vector<std::shared_ptr<Object>>& args) override {
        if (args.size() != 1 || !args[0]) {
            throw RuntimeError("");
        }
        return (Is<Number>(args[0])) ? "#t" : "#f";
    }
};
class Equal : public Function {
public:
    std::string Apply(const std::vector<std::shared_ptr<Object>>& args) override {
        for (size_t i = 0; i < args.size(); ++i) {
            if (!args[i] || !Is<Number>(args[i])) {
                throw RuntimeError("");
            }
        }
        for (size_t i = 1; i < args.size(); ++i) {
            if (As<Number>(args[i])->GetValue() != As<Number>(args[0])->GetValue()) {
                return "#f";
            }
        }
        return "#t";
    }
};
class Greater : public Function {
public:
    std::string Apply(const std::vector<std::shared_ptr<Object>>& args) override {
        for (size_t i = 0; i < args.size(); ++i) {
            if (!args[i] || !Is<Number>(args[i])) {
                throw RuntimeError("");
            }
        }
        for (size_t i = 1; i < args.size(); ++i) {
            if (As<Number>(args[i - 1])->GetValue() <= As<Number>(args[i])->GetValue()) {
                return "#f";
            }
        }
        return "#t";
    }
};
class GreaterEqual : public Function {
public:
    std::string Apply(const std::vector<std::shared_ptr<Object>>& args) override {
        for (size_t i = 0; i < args.size(); ++i) {
            if (!args[i] || !Is<Number>(args[i])) {
                throw RuntimeError("");
            }
        }
        for (size_t i = 1; i < args.size(); ++i) {
            if (As<Number>(args[i - 1])->GetValue() < As<Number>(args[i])->GetValue()) {
                return "#f";
            }
        }
        return "#t";
    }
};
class Less : public Function {
public:
    std::string Apply(const std::vector<std::shared_ptr<Object>>& args) override {
        for (size_t i = 0; i < args.size(); ++i) {
            if (!args[i] || !Is<Number>(args[i])) {
                throw RuntimeError("");
            }
        }
        for (size_t i = 1; i < args.size(); ++i) {
            if (As<Number>(args[i - 1])->GetValue() >= As<Number>(args[i])->GetValue()) {
                return "#f";
            }
        }
        return "#t";
    }
};
class LessEqual : public Function {
public:
    std::string Apply(const std::vector<std::shared_ptr<Object>>& args) override {
        for (size_t i = 0; i < args.size(); ++i) {
            if (!args[i] || !Is<Number>(args[i])) {
                throw RuntimeError("");
            }
        }
        for (size_t i = 1; i < args.size(); ++i) {
            if (As<Number>(args[i - 1])->GetValue() > As<Number>(args[i])->GetValue()) {
                return "#f";
            }
        }
        return "#t";
    }
};
class Plus : public Function {
public:
    std::string Apply(const std::vector<std::shared_ptr<Object>>& args) override {
        for (size_t i = 0; i < args.size(); ++i) {
            if (!args[i] || !Is<Number>(args[i])) {
                throw RuntimeError("");
            }
        }
        int64_t answer = 0;
        for (size_t i = 0; i < args.size(); ++i) {
            answer += As<Number>(args[i])->GetValue();
        }
        return std::to_string(answer);
    }
};
class Minus : public Function {
public:
    std::string Apply(const std::vector<std::shared_ptr<Object>>& args) override {
        if (args.empty()) {
            throw RuntimeError("");
        }
        for (size_t i = 0; i < args.size(); ++i) {
            if (!args[i] || !Is<Number>(args[i])) {
                throw RuntimeError("");
            }
        }
        int64_t answer = As<Number>(args[0])->GetValue();
        for (size_t i = 1; i < args.size(); ++i) {
            answer -= As<Number>(args[i])->GetValue();
        }
        return std::to_string(answer);
    }
};
class Multiply : public Function {
public:
    std::string Apply(const std::vector<std::shared_ptr<Object>>& args) override {
        for (size_t i = 0; i < args.size(); ++i) {
            if (!args[i] || !Is<Number>(args[i])) {
                throw RuntimeError("");
            }
        }
        int64_t answer = 1;
        for (size_t i = 0; i < args.size(); ++i) {
            answer *= As<Number>(args[i])->GetValue();
        }
        return std::to_string(answer);
    }
};
class Divide : public Function {
public:
    std::string Apply(const std::vector<std::shared_ptr<Object>>& args) override {
        if (args.empty()) {
            throw RuntimeError("");
        }
        for (size_t i = 0; i < args.size(); ++i) {
            if (!args[i] || !Is<Number>(args[i])) {
                throw RuntimeError("");
            }
        }
        int64_t answer = As<Number>(args[0])->GetValue();
        for (size_t i = 1; i < args.size(); ++i) {
            answer /= As<Number>(args[i])->GetValue();
        }
        return std::to_string(answer);
    }
};
class Max : public Function {
public:
    std::string Apply(const std::vector<std::shared_ptr<Object>>& args) override {
        if (args.empty()) {
            throw RuntimeError("");
        }
        for (size_t i = 0; i < args.size(); ++i) {
            if (!args[i] || !Is<Number>(args[i])) {
                throw RuntimeError("");
            }
        }
        int64_t answer = As<Number>(args[0])->GetValue();
        for (size_t i = 1; i < args.size(); ++i) {
            if (As<Number>(args[i])->GetValue() > answer) {
                answer = As<Number>(args[i])->GetValue();
            }
        }
        return std::to_string(answer);
    }
};
class Min : public Function {
public:
    std::string Apply(const std::vector<std::shared_ptr<Object>>& args) override {
        if (args.empty()) {
            throw RuntimeError("");
        }
        for (size_t i = 0; i < args.size(); ++i) {
            if (!args[i] || !Is<Number>(args[i])) {
                throw RuntimeError("");
            }
        }
        int64_t answer = As<Number>(args[0])->GetValue();
        for (size_t i = 1; i < args.size(); ++i) {
            if (As<Number>(args[i])->GetValue() < answer) {
                answer = As<Number>(args[i])->GetValue();
            }
        }
        return std::to_string(answer);
    }
};
class Abs : public Function {
public:
    std::string Apply(const std::vector<std::shared_ptr<Object>>& args) override {
        if (args.size() != 1 || !Is<Number>(args[0])) {
            throw RuntimeError("");
        }
        return std::to_string(std::abs(As<Number>(args[0])->GetValue()));
    }
};
class IsBool : public Function {
public:
    std::string Apply(const std::vector<std::shared_ptr<Object>>& args) override {
        if (args.size() != 1 || !args[0]) {
            throw RuntimeError("");
        }
        return Is<Bool>(args[0]) ? "#t" : "#f";
    }
};
class Not : public Function {
public:
    std::string Apply(const std::vector<std::shared_ptr<Object>>& args) override {
        if (args.size() != 1 || !args[0]) {
            throw RuntimeError("");
        }
        return (args[0] && Is<Bool>(args[0]) && !As<Bool>(args[0])->GetValue()) ? "#t" : "#f";
    }
};
class Or : public Function {
public:
    std::string Apply(const std::vector<std::shared_ptr<Object>>& args) override {
        if (args.empty()) {
            return "#f";
        }
        for (auto& elem : args) {
            if (elem && Is<Bool>(elem) && As<Bool>(elem)->GetValue()) {
                return "#t";
            }
        }
        return args.back()->MakeString();
    }
};
class And : public Function {
public:
    std::string Apply(const std::vector<std::shared_ptr<Object>>& args) override {
        if (args.empty()) {
            return "#t";
        }
        for (auto& elem : args) {
            if (elem && Is<Bool>(elem) && !As<Bool>(elem)->GetValue()) {
                return "#f";
            }
        }
        return args.back()->MakeString();
    }
};
class Quote : public Function {
public:
    std::string Apply(const std::vector<std::shared_ptr<Object>>& args) override {
        if (args.size() != 1) {
            throw RuntimeError("");
        }
        std::shared_ptr<Object> current = args[0];
        if (current == nullptr) {
            return "()";
        }
        if (Is<Number>(current)) {
            return As<Number>(current)->MakeString();
        }
        if (Is<Bool>(current)) {
            return As<Bool>(current)->MakeString();
        }
        if (Is<Symbol>(current)) {
            return As<Symbol>(current)->MakeString();
        } else {
            return "(" + CellQuote(As<Cell>(current)) + ")";
        }
    }
    std::string CellQuote(std::shared_ptr<Cell> obj) {
        if (!obj->GetFirst()) {
            return "()";
        }
        if (!obj->GetSecond()) {
            if (Is<Number>(obj->GetFirst())) {
                return As<Number>(obj->GetFirst())->MakeString();
            }
            if (Is<Bool>(obj->GetFirst())) {
                return As<Bool>(obj->GetFirst())->MakeString();
            }
            if (Is<Symbol>(obj->GetFirst())) {
                return As<Symbol>(obj->GetFirst())->MakeString();
            }
            return CellQuote(As<Cell>(obj->GetFirst()));
        }
        if (Is<Number>(obj->GetFirst()) && Is<Number>(obj->GetSecond())) {
            return As<Number>(obj->GetFirst())->MakeString() + " . " +
                   As<Number>(obj->GetSecond())->MakeString();
        }
        return ObjectQuote(obj->GetFirst()) + " " + ObjectQuote(obj->GetSecond());
    }
    std::string ObjectQuote(std::shared_ptr<Object> obj) {
        if (Is<Number>(obj)) {
            return As<Number>(obj)->MakeString();
        }
        if (Is<Bool>(obj)) {
            return As<Bool>(obj)->MakeString();
        }
        if (Is<Symbol>(obj)) {
            return As<Symbol>(obj)->MakeString();
        }
        return CellQuote(As<Cell>(obj));
    }
};
class IsPair : public Function {
public:
    std::string Apply(const std::vector<std::shared_ptr<Object>>& args) override {
        if (args.size() != 1 || !args[0]) {
            throw RuntimeError("");
        }
        int cnt = 0;
        for (char a : As<Symbol>(args[0])->GetName()) {
            if (std::isdigit(a)) {
                ++cnt;
            }
        }
        return (cnt == 2) ? "#t" : "#f";
    }
};
class IsList : public Function {
public:
    std::string Apply(const std::vector<std::shared_ptr<Object>>& args) override {
        if (args.size() != 1 || !args[0]) {
            throw RuntimeError("");
        }
        return (As<Symbol>(args[0])->GetName().find(".") == std::string::npos) ? "#t" : "#f";
    }
};
class IsNull : public Function {
public:
    std::string Apply(const std::vector<std::shared_ptr<Object>>& args) override {
        if (args.size() != 1 || !args[0]) {
            throw RuntimeError("");
        }
        return (As<Symbol>(args[0])->GetName() == "()") ? "#t" : "#f";
    }
};
class Cons : public Function {
public:
    std::string Apply(const std::vector<std::shared_ptr<Object>>& args) override {
        if (args.size() != 2) {
            throw RuntimeError("");
        }
        for (size_t i = 0; i < args.size(); ++i) {
            if (!args[i] || !Is<Number>(args[i])) {
                throw RuntimeError("");
            }
        }
        return "(" + As<Number>(args[0])->MakeString() + " . " + As<Number>(args[1])->MakeString() +
               ")";
    }
};
class Car : public Function {
public:
    std::string Apply(const std::vector<std::shared_ptr<Object>>& args) override {
        if (args.size() != 1 || !args[0] || args[0]->MakeString() == "()") {
            throw RuntimeError("");
        }
        std::string result;
        for (size_t i = 1; i < args[0]->MakeString().size() - 1; ++i) {
            if (std::isdigit(args[0]->MakeString()[i])) {
                result += args[0]->MakeString()[i];
                continue;
            }
            break;
        }
        return result;
    }
};
class Cdr : public Function {
public:
    std::string Apply(const std::vector<std::shared_ptr<Object>>& args) override {
        if (args.size() != 1 || !args[0] || args[0]->MakeString() == "()") {
            throw RuntimeError("");
        }
        std::string string = args[0]->MakeString();
        auto space = string.find(' ');
        auto point = string.find('.');
        if (space == std::string::npos) {
            return "()";
        }
        if (space + 1 == point) {
            string.pop_back();
            return string.substr(point + 2, string.size());
        }
        return "(" + string.substr(space + 1, string.size());
    }
};
class List : public Function {
public:
    std::string Apply(const std::vector<std::shared_ptr<Object>>& args) override {
        if (args.empty()) {
            return "()";
        }
        for (size_t i = 0; i < args.size(); ++i) {
            if (!args[i] || !Is<Number>(args[i])) {
                throw RuntimeError("");
            }
        }
        std::string list;
        for (size_t i = 0; i < args.size() - 1; ++i) {
            list += args[i]->MakeString() + ' ';
        }
        list += args[args.size() - 1]->MakeString();

        return "(" + list + ")";
    }
};
class ListRef : public Function {
public:
    std::string Apply(const std::vector<std::shared_ptr<Object>>& args) override {
        if (args.size() != 2 || !Is<Symbol>(args[0]) || !Is<Number>(args[1]) ||
            As<Symbol>(args[0])->GetName().front() != '(' ||
            As<Symbol>(args[0])->GetName().back() != ')') {
            throw RuntimeError("");
        }
        std::string string = As<Symbol>(args[0])->GetName(), result;
        int64_t index = As<Number>(args[1])->GetValue(), cur_index = 0;
        bool flag = true;
        for (size_t i = 1; i < string.size() - 1; ++i) {
            if (std::isspace(string[i])) {
                flag = true;
                if (cur_index == index + 1) {
                    break;
                }
            } else if (std::isdigit(string[i])) {
                if (flag) {
                    flag = false;
                    ++cur_index;
                }
                if (cur_index == index + 1) {
                    result += string[i];
                }
            }
        }
        if (result.empty()) {
            throw RuntimeError("");
        }
        return result;
    }
};
class ListTail : public Function {
public:
    std::string Apply(const std::vector<std::shared_ptr<Object>>& args) override {
        if (args.size() != 2 || !Is<Symbol>(args[0]) || !Is<Number>(args[1]) ||
            As<Symbol>(args[0])->GetName().front() != '(' ||
            As<Symbol>(args[0])->GetName().back() != ')') {
            throw RuntimeError("");
        }
        std::string string = As<Symbol>(args[0])->GetName(), result;
        int64_t index = As<Number>(args[1])->GetValue(), cur_index = 0;
        bool flag = true;
        for (size_t i = 1; i < string.size() - 1; ++i) {
            if (std::isspace(string[i])) {
                flag = true;
                if (cur_index >= index + 1) {
                    result += string[i];
                }
            } else if (std::isdigit(string[i])) {
                if (flag) {
                    flag = false;
                    ++cur_index;
                }
                if (cur_index >= index + 1) {
                    result += string[i];
                }
            }
        }
        if (result.empty() && cur_index < index) {
            throw RuntimeError("");
        }
        return "(" + result + ")";
    }
};
