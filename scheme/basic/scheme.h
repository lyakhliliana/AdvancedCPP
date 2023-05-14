#pragma once

#include <string>
#include <map>
#include "parser.h"

class Interpreter {
public:
    Interpreter();
    std::string Run(const std::string& string);

private:
    void MakeArgs(std::vector<std::shared_ptr<Object>>& args, std::shared_ptr<Object> object,
                  bool flag = false);
    std::string Calc(std::shared_ptr<Cell> obj, bool flag = false);
    std::map<std::string, std::shared_ptr<Function>> functions_;
};
