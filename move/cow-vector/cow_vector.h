#pragma once
#include <iostream>
#include <vector>
#include <cstdint>
#include <string>

struct State {
    State() = default;
    State(std::vector<std::string>& vector) : vector_(vector) {
    }
    const std::string& Get(size_t n) const {
        return vector_[n];
    }
    std::string& Get(size_t n) {
        return vector_[n];
    }
    const std::string& Back() const {
        return vector_.back();
    }
    size_t Size() const {
        return vector_.size();
    }

public:
    int ref_count_ = 1;
    std::vector<std::string> vector_{};
};

class COWVector {
public:
    COWVector() : state_(new State) {
    }
    ~COWVector() {
        if (state_->ref_count_ == 1) {
            delete state_;
            return;
        }
        --state_->ref_count_;
    }

    COWVector(const COWVector& other) {
        state_ = other.state_;
        ++state_->ref_count_;
    }
    COWVector(COWVector&& other) {
        state_ = other.state_;
        other.state_ = nullptr;
    }

    COWVector& operator=(const COWVector& other) {
        if (state_ == other.state_) {
            return *this;
        }
        if (state_->ref_count_ == 1) {
            delete state_;
        }
        --state_->ref_count_;
        state_ = other.state_;
        ++state_->ref_count_;
        return *this;
    }
    COWVector& operator=(COWVector&& other) {
        if (state_ == other.state_) {
            return *this;
        }
        if (state_->ref_count_ == 1) {
            delete state_;
        }
        --state_->ref_count_;
        state_ = other.state_;
        other.state_ = nullptr;
        return *this;
    }

    size_t Size() const {
        return state_->Size();
    }

    void Resize(size_t size) {
        if (state_->ref_count_ == 1) {
            state_->vector_.resize(size);
            return;
        }
        --state_->ref_count_;
        State* temp = new State(state_->vector_);
        temp->vector_.resize(size);
        state_ = temp;
    }

    const std::string& Get(size_t at) {
        return state_->Get(at);
    }
    const std::string& Back() {
        return state_->Back();
    }

    void PushBack(const std::string& value) {
        if (state_->ref_count_ == 1) {
            state_->vector_.push_back(value);
            return;
        }
        --state_->ref_count_;
        State* temp = new State(state_->vector_);
        temp->vector_.push_back(value);
        state_ = temp;
    }

    void Set(size_t at, const std::string& value) {
        if (state_->Get(at) == value) {
            return;
        }
        if (state_->ref_count_ == 1) {
            state_->Get(at) = value;
            return;
        }
        --state_->ref_count_;
        State* temp = new State(state_->vector_);
        temp->Get(at) = value;
        state_ = temp;
    }

private:
    State* state_;
};
