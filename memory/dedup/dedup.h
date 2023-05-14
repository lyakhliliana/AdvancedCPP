#pragma once

#include <memory>
#include <vector>
#include <string>

using std::string;

std::vector<std::unique_ptr<string>> Duplicate(const std::vector<std::shared_ptr<string>>& items) {
    std::vector<std::unique_ptr<string>> unique_items(items.size());
    for (size_t i = 0; i < items.size(); ++i) {
        unique_items[i] = std::make_unique<string>(*items[i]);
    }
    return unique_items;
}

std::vector<std::shared_ptr<string>> DeDuplicate(
    const std::vector<std::unique_ptr<string>>& items) {
    std::vector<std::shared_ptr<string>> shared_items(items.size());
    for (size_t i = 0; i < items.size(); ++i) {
        bool flag = false;
        for (size_t j = 0; j < i; ++j) {
            if (*items[i] == *items[j]) {
                flag = true;
                shared_items[i] = shared_items[j];
                break;
            }
        }
        if (!flag) {
            shared_items[i] = std::make_shared<string>(*items[i]);
        }
    }
    return shared_items;
}
