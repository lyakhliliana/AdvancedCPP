#pragma once

#include <variant>
#include <optional>
#include <istream>
#include <regex>
#include "error.h"

struct SymbolToken {
    std::string name;
    SymbolToken(std::string temp) : name(temp) {
    }
    bool operator==(const SymbolToken& other) const {
        return name == other.name;
    }
};

struct QuoteToken {
    bool operator==(const QuoteToken&) const {
        return true;
    }
};

struct DotToken {
    bool operator==(const DotToken&) const {
        return true;
    }
};

enum class BracketToken { OPEN, CLOSE };

struct ConstantToken {
    int value;
    ConstantToken(int v) : value(v) {
    }
    bool operator==(const ConstantToken& other) const {
        return value == other.value;
    }
};
enum class BooleanToken { TRUE, FALSE };

using Token =
    std::variant<ConstantToken, BracketToken, SymbolToken, QuoteToken, DotToken, BooleanToken>;

class Tokenizer {
public:
    Tokenizer(std::istream* in) : in_(in) {
        Next();
    }

    bool IsEnd() {
        return !token_;
    }

    void Next();

    Token GetToken() {
        return *token_;
    }

private:
    std::istream* in_;
    std::optional<Token> token_;
};