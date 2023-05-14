#pragma once

#include <string_view>
#include <string>
#include <cctype>
#include <vector>
#include <unistd.h>
#include <fcntl.h>

bool StartsWith(std::string_view string, std::string_view text);
bool EndsWith(std::string_view string, std::string_view text);
std::string_view StripPrefix(std::string_view string, std::string_view prefix);
std::string_view StripSuffix(std::string_view string, std::string_view suffix);
std::string_view ClippedSubstr(std::string_view s, size_t pos, size_t n);
std::string_view StripAsciiWhitespace(std::string_view string);
std::vector<std::string_view> StrSplit(std::string_view text, std::string_view delim);
std::string ReadN(const std::string& filename, size_t n);
std::string AddSlash(std::string_view path);
std::string_view RemoveSlash(std::string_view path);
std::string_view Dirname(std::string_view path);
std::string_view Basename(std::string_view path);
std::string CollapseSlashes(std::string_view path);
std::string StrJoin(const std::vector<std::string_view>& strings, std::string_view delimiter);

///======================================
/// help StrCat functions

size_t TemplateSize(const std::string& s);
size_t TemplateSize(std::string_view s);
size_t TemplateSize(const char* s);

void ToString(std::string& ans, const std::string& s);
void ToString(std::string& ans, std::string_view s);
void ToString(std::string& ans, const char* s);

template <typename T>
size_t TemplateSize(T t) {
    size_t count = 0, cur = 1;
    if (t % 10 != 0 && t < 0) {
        ++t;
    }
    if (t <= 0) {
        t *= -1;
        ++count;
    }
    while (static_cast<size_t>(t) >= cur && count < 20) {
        cur *= 10;
        ++count;
    }
    if (static_cast<size_t>(t) > cur && count == 19) {
        ++count;
    }
    return count;
}

template <class T>
void ToString(std::string& ans, const T& n) {
    size_t old = ans.size();
    size_t size = TemplateSize(n);
    T cur = n;
    if (cur == 0) {
        ans.push_back('0');
        return;
    }
    T e = (cur < 0) ? (-1) : (1);
    while (cur != 0) {
        ans.push_back(static_cast<char>('0' + e * (cur % 10)));
        cur /= 10;
    }
    if (e == static_cast<T>(-1)) {
        ans.push_back('-');
    }
    std::reverse(ans.begin() + old, ans.begin() + old + size);
}

template <typename T, typename... Params>
void Size(size_t& count, T&& one, Params&&... params) {
    count += TemplateSize(one);
    (Size(count, std::forward<Params>(params)), ...);
}

template <typename T, typename... Params>
void MakeString(std::string& answer, T&& one, Params&&... params) {
    ToString(answer, one);
    (MakeString(answer, std::forward<Params>(params)), ...);
}

///=========================
template <class... Params>
std::string StrCat(Params&&... params) {
    std::string answer;
    size_t size = 0;
    (Size(size, std::forward<Params>(params)), ...);
    answer.reserve(size);
    (MakeString(answer, std::forward<Params>(params)), ...);
    return answer;
}
