#pragma once

#include <vector>

template <class Functor>
class ReverseBinaryFunctor {
public:
    ReverseBinaryFunctor(Functor& functor) : functor_(functor) {
    }
    template <typename T>
    bool operator()(T& x, T& y) {
        return !functor_(x, y);
    }

private:
    Functor functor_;
};

template <class Functor>
class ReverseUnaryFunctor {
public:
    ReverseUnaryFunctor(Functor& functor) : functor_(functor) {
    }
    template <typename T>
    bool operator()(T& x) {
        return !functor_(x);
    }

private:
    Functor functor_;
};

template <class Functor>
ReverseUnaryFunctor<Functor> MakeReverseUnaryFunctor(Functor functor) {
    return ReverseUnaryFunctor<Functor>(functor);
}

template <class Functor>
ReverseBinaryFunctor<Functor> MakeReverseBinaryFunctor(Functor functor) {
    return ReverseBinaryFunctor<Functor>(functor);
}
