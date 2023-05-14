#include "lru_cache.h"

LruCache::LruCache(size_t max_size) : cache_size_(max_size) {
}

void LruCache::Set(const std::string& key, const std::string& value) {
    auto it = map_.find(key);
    if (it != map_.end()) {
        list_.erase(it->second);
        map_.erase(it);
    }
    list_.push_front(std::make_pair(key, value));
    map_.insert(std::make_pair(key, list_.begin()));
    if (map_.size() > cache_size_) {
        auto last_it = list_.end();
        --last_it;
        map_.erase(last_it->first);
        list_.pop_back();
    }
}

bool LruCache::Get(const std::string& key, std::string* value) {
    if (map_.contains(key)) {
        auto it = map_.find(key);
        *value = map_[key]->second;
        list_.splice(list_.begin(), list_, it->second);
        return true;
    }
    return false;
}
