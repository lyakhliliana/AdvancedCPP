#include "is_prime.h"
#include <cmath>
#include <algorithm>
#include <thread>
#include <atomic>

void IsPrimeHelp(std::atomic<bool>& answer, uint64_t x, uint64_t bound, unsigned query, int core) {
    for (auto i = 2ull + query; i < bound; i += core) {
        if (!answer.load()) {
            return;
        }
        if (x % i == 0) {
            answer.store(false);
            return;
        }
    }
}

bool IsPrime(uint64_t x) {
    if (x <= 1) {
        return false;
    }
    uint64_t root = sqrt(x);
    auto bound = std::min(root + 6, x);
    auto core_num = std::thread::hardware_concurrency();
    std::atomic<bool> answer = true;
    std::vector<std::thread> workers;
    for (unsigned i = 0; i < core_num; ++i) {
        workers.emplace_back(IsPrimeHelp, std::ref(answer), x, bound, i, core_num);
    }
    for (std::thread& t : workers) {
        t.join();
    }
    return answer.load();
}
