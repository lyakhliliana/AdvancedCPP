#include "string_operations.h"
bool StartsWith(std::string_view string, std::string_view text) {
    return string.starts_with(text);
}

bool EndsWith(std::string_view string, std::string_view text) {
    return string.ends_with(text);
}

std::string_view StripPrefix(std::string_view string, std::string_view prefix) {
    if (string.starts_with(prefix)) {
        string.remove_prefix(prefix.size());
    }
    return string;
}

std::string_view StripSuffix(std::string_view string, std::string_view prefix) {
    if (string.ends_with(prefix)) {
        string.remove_suffix(prefix.size());
    }
    return string;
}

std::string_view ClippedSubstr(std::string_view s, size_t pos, size_t n) {
    return (n <= s.size()) ? s.substr(pos, n) : s;
}

std::string_view StripAsciiWhitespace(std::string_view string) {
    size_t pref_space = 0, suf_space = 0;
    while (pref_space < string.size() && std::isspace(string[pref_space])) {
        ++pref_space;
    }
    while (string.size() - suf_space - 1 > pref_space &&
           std::isspace(string[string.size() - suf_space - 1])) {
        ++suf_space;
    }
    return string.substr(pref_space, string.size() - pref_space - suf_space);
}

std::vector<std::string_view> StrSplit(std::string_view text, std::string_view delim) {
    size_t to_reserve = 1, del_size = delim.size(), prev_begin = 0;
    for (size_t i = 0; i < text.size(); ++i) {
        if (text.substr(i, del_size) == delim) {
            ++to_reserve;
        }
    }
    std::vector<std::string_view> answer;
    answer.reserve(to_reserve);
    for (size_t i = 0; i < text.size(); ++i) {
        if (text.substr(i, del_size) == delim) {
            answer.push_back(text.substr(prev_begin, i - prev_begin));
            prev_begin = i + del_size;
        }
    }
    answer.push_back(text.substr(prev_begin, text.size() - prev_begin + 1));
    return answer;
}

std::string ReadN(const std::string& filename, size_t n) {
    ssize_t fd = open(filename.c_str(), O_RDONLY);
    if (fd == -1) {
        return "";
    }
    std::string answer(n, 'a');
    if (read(fd, answer.data(), n) != static_cast<ssize_t>(n)) {
        return "";
    }
    return answer;
}

std::string AddSlash(std::string_view path) {
    if (path.back() == '/') {
        return std::string(path);
    }
    std::string answer(path.size() + 1, '0');
    std::copy(path.begin(), path.end(), answer.begin());
    answer[answer.size() - 1] = '/';
    return answer;
}

std::string_view RemoveSlash(std::string_view path) {
    if (path.back() == '/' && path != "/") {
        path.remove_suffix(1);
    }
    return path;
}

std::string_view Dirname(std::string_view path) {
    size_t ind = path.find_last_of('/');
    if (ind == 0) {
        return "/";
    }
    return path.substr(0, ind);
}

std::string_view Basename(std::string_view path) {
    size_t ind = path.find_last_of('/') + 1;
    return path.substr(ind, path.size() - ind + 1);
}

std::string CollapseSlashes(std::string_view path) {
    size_t to_reserve = 1;
    for (size_t i = 1; i < path.size(); ++i) {
        if (path[i] != '/' || path[i - 1] != '/') {
            ++to_reserve;
        }
    }
    std::string answer;
    answer.reserve(to_reserve);
    for (size_t i = 0; i < path.size(); ++i) {
        if (i == 0 || path[i] != '/' || path[i - 1] != '/') {
            answer.push_back(path[i]);
        }
    }
    return answer;
}

std::string StrJoin(const std::vector<std::string_view>& strings, std::string_view delimiter) {
    if (strings.empty()) {
        return "";
    }
    size_t to_reserve = delimiter.size() * (strings.size() - 1);
    for (std::string_view str : strings) {
        to_reserve += str.size();
    }
    std::string answer;
    answer.reserve(to_reserve);
    for (size_t i = 0; i < strings.size(); ++i) {
        for (char ch : strings[i]) {
            answer.push_back(ch);
        }
        if (i != strings.size() - 1) {
            for (char ch : delimiter) {
                answer.push_back(ch);
            }
        }
    }
    return answer;
}

///====================================

size_t TemplateSize(const std::string& s) {
    return s.size();
}

size_t TemplateSize(std::string_view s) {
    return s.size();
}

size_t TemplateSize(const char* s) {
    std::string_view t = s;
    return t.size();
}

void ToString(std::string& ans, const std::string& s) {
    for (const char& c : s) {
        ans.push_back(c);
    }
}

void ToString(std::string& ans, std::string_view s) {
    for (const char& c : s) {
        ans.push_back(c);
    }
}

void ToString(std::string& ans, const char* s) {
    std::string_view temp = s;
    for (const char& c : temp) {
        ans.push_back(c);
    }
}
