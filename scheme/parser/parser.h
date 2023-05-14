#pragma once

#include "object.h"
#include <tokenizer.h>
#include <queue>

std::shared_ptr<Object> Read(Tokenizer* tokenizer);
std::shared_ptr<Object> ReadList(Tokenizer* tokenizer);
std::shared_ptr<Object> ForCell(std::queue<std::shared_ptr<Object>>& vec);