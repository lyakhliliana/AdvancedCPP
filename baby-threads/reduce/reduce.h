#pragma once

#include <thread>
#include <vector>
#include <mutex>
#include <utility>
#include <iterator>
// template<class RandomAccessIterator>
// bool Check(RandomAccessIterator first, RandomAccessIterator last, RandomAccessIterator step){
// }
template <class RandomAccessIterator, class T, class Func>
T Reduce(RandomAccessIterator first, RandomAccessIterator last, const T& initial_value, Func func) {
    auto cores_num = std::thread::hardware_concurrency();
    std::vector<std::pair<bool, T>> for_ans(cores_num);
    std::vector<std::thread> workers(cores_num);
    std::mutex mutex;
    for (unsigned i = 0; i < cores_num; ++i) {
        workers[i] = std::thread([&func, &for_ans, first, last, i, cores_num, &mutex] {
            if (std::distance(first, last) <= i) {
                //            }
                //            if (first + i >= last) {
                {
                    auto guard = std::lock_guard{mutex};
                    for_ans[i] = {false, T()};
                }
                return;
            }
            auto it = (first + i);
            T cur_ans(*it);
            // while ((it + cores_num) < last) {
            while (std::distance(it, last) > cores_num) {
                it += cores_num;
                cur_ans = func(cur_ans, *(it));
            }
            {
                auto guard = std::lock_guard{mutex};
                for_ans[i] = {true, cur_ans};
            }
        });
    }
    for (std::thread& t : workers) {
        t.join();
    }
    T answer(initial_value);
    for (unsigned i = 0; i < cores_num; ++i) {
        if (for_ans[i].first) {
            answer = func(answer, for_ans[i].second);
        }
    }
    return answer;
}
