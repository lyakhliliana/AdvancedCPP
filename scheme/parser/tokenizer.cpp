#include <tokenizer.h>

bool BeginString(char c) {
    std::string begin = "<=>*/#";
    return std::isalpha(c) || begin.find(c) != std::string::npos;
}
bool MiddleString(char c) {
    std::string middle = "<=>*/#!?-";
    return std::isalpha(c) || middle.find(c) != std::string::npos || std::isdigit(c);
}
bool BeginConstant(char c) {
    std::string begin = "+-";
    return std::isdigit(c) || begin.find(c) != std::string::npos;
}
void Tokenizer::Next() {
    char symbol = in_->get();
    while (symbol != EOF && std::isspace(symbol)) {
        symbol = in_->get();
    }
    if (symbol == EOF) {
        token_.reset();
        return;
    }
    if (symbol == '.') {
        token_ = DotToken();
    } else if (symbol == '(') {
        token_ = BracketToken::OPEN;
    } else if (symbol == ')') {
        token_ = BracketToken::CLOSE;
    } else if (symbol == '\'') {
        token_ = QuoteToken();
    } else if (symbol == '#' && in_->peek() == 't') {
        in_->get();
        token_ = BooleanToken::TRUE;
    } else if (symbol == '#' && in_->peek() == 'f') {
        in_->get();
        token_ = BooleanToken::FALSE;
    } else if ((symbol == '+' || symbol == '-') && !std::isdigit(in_->peek())) {
        token_ = SymbolToken(std::string{symbol});
    } else if (BeginString(symbol)) {
        std::string ans(1, symbol);
        while (MiddleString(in_->peek())) {
            ans += static_cast<char>(in_->get());
        }
        token_ = SymbolToken(ans);
    } else if (BeginConstant(symbol)) {
        std::string ans(1, symbol);
        while (std::isdigit(in_->peek())) {
            ans += static_cast<char>(in_->get());
        }
        token_ = ConstantToken(std::stoi(ans));
    } else {
        throw SyntaxError("syntax");
    }
}
