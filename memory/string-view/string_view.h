#pragma once

#include <string>
#include <cstring>

class StringView {
public:
    StringView(const std::string& const_str, size_t start_index = 0,
               size_t len = std::string::npos) {
        it_start_ = const_str.c_str();
        start_ = start_index;
        size_ = len == std::string::npos ? const_str.size() - start_index : len;
        if (len + start_index >= const_str.size()) {
            size_ = const_str.size() - start_index;
        }
    }

    StringView(const char* const_str) {
        it_start_ = const_str;
        start_ = 0;
        size_ = std::strlen(const_str);
    }

    StringView(const char* const_str, size_t len) {
        it_start_ = const_str;
        start_ = 0;
        size_ = std::strlen(const_str);
        if (len < size_) {
            size_ = len;
        }
    }

    char operator[](size_t index) const {
        auto current_it = it_start_;
        current_it += index + start_;
        return *current_it;
    }

    size_t Size() const {
        return size_;
    }

private:
    const char* it_start_;
    size_t start_;
    size_t size_;
};
