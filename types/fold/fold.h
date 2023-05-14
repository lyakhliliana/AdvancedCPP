#pragma once
#include <vector>

struct Sum {
    void operator()(int& init, int elem) {
        init += elem;
    }
};

struct Prod {
    void operator()(int& left, int elem) {
        left *= elem;
    }
};

struct Concat {
    void operator()(std::vector<int>& init, const std::vector<int>& elem) {
        init.insert(init.end(), elem.begin(), elem.end());
    }
};

template <class Iterator, class T, class BinaryOp>
T Fold(Iterator first, Iterator last, T init, BinaryOp func) {
    while (first != last) {
        func(init, *(first++));
    }
    return init;
}

class Length {
public:
    Length(int* count_ptr) : count_(count_ptr){};

    template <class T>
    void operator()(T& init, T elem) {
        ++(*count_);
        init += elem;
    }

private:
    int* count_;
};
