#pragma once

#include <string>
#include <list>
#include <unordered_map>

class LruCache {
public:
    LruCache(size_t max_size);

    void Set(const std::string& key, const std::string& value);

    bool Get(const std::string& key, std::string* value);

private:
    std::list<std::pair<std::string, std::string>> list_;
    std::unordered_map<std::string, decltype(list_.begin())> map_;
    size_t cache_size_;
};
