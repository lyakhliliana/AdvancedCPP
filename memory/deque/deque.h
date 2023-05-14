#pragma once

#include <initializer_list>
#include <algorithm>
#include <memory>

size_t Two(size_t n) {
    size_t i = 1;
    while (i <= n) {
        i *= 2;
    }
    return i;
}
class Block {
public:
    int& operator[](size_t ind) {
        return arr[ind];
    }
    std::array<int, 128> arr;
};
using BlockPtr = std::shared_ptr<Block>;

class Deque {
public:
    Deque() {
        buffer_ = std::make_unique<BlockPtr[]>(1);
        BlockPtr temp(new Block);
        buffer_[0] = temp;
        size_ = 0;
        head_ = 0;
        tail_ = 0;
        num_blocks_ = 1;
    }

    Deque(const Deque& rhs) {
        std::unique_ptr<std::shared_ptr<Block>[]> tmp(new BlockPtr[rhs.num_blocks_]);
        for (size_t i = 0; i < rhs.num_blocks_; ++i) {
            BlockPtr temp(new Block());
            *temp = *(rhs.buffer_[i]);
            tmp[i] = std::move(temp);
        }
        size_ = rhs.size_;
        head_ = rhs.head_;
        start_head_ = rhs.start_head_;
        tail_ = rhs.tail_;
        start_tail_ = rhs.start_tail_;
        num_blocks_ = rhs.num_blocks_;
        buffer_ = std::move(tmp);
    }

    Deque(Deque&& rhs) {
        buffer_ = std::move(rhs.buffer_);
        size_ = rhs.size_;
        head_ = rhs.head_;
        start_head_ = rhs.start_head_;
        tail_ = rhs.tail_;
        start_tail_ = rhs.start_tail_;
        num_blocks_ = rhs.num_blocks_;
    }

    explicit Deque(size_t size) {
        num_blocks_ = Two(size / 128);
        buffer_ = std::make_unique<BlockPtr[]>(num_blocks_);
        for (size_t i = 0; i < size / 128; ++i) {
            BlockPtr temp(new Block);
            buffer_[i] = temp;
            for (size_t j = 0; j < 128; ++j) {
                (*buffer_[i])[j] = 0;
            }
        }
        BlockPtr temp(new Block);
        buffer_[size / 128] = temp;
        for (size_t j = 0; j < size % 128; ++j) {
            (*buffer_[size / 128])[j] = 0;
        }
        head_ = size;
        size_ = size;
        tail_ = 0;
    }

    Deque(std::initializer_list<int> list) {
        num_blocks_ = Two(list.size() / 128);
        buffer_ = std::make_unique<BlockPtr[]>(num_blocks_);
        auto it = list.begin();
        for (size_t i = 0; i < list.size() / 128; ++i) {
            BlockPtr temp(new Block);
            buffer_[i] = temp;
            for (size_t j = 0; j < 128; ++j) {
                (*buffer_[i])[j] = *(++it);
            }
        }
        BlockPtr temp(new Block);
        buffer_[list.size() / 128] = temp;
        for (size_t j = 0; j < list.size() % 128; ++j) {
            (*buffer_[list.size() / 128])[j] = *(it++);
        }
        size_ = list.size();
        head_ = list.size();
        tail_ = 0;
    }

    Deque& operator=(Deque rhs) {
        Swap(rhs);
        return *this;
    }

    void Swap(Deque& rhs) {
        std::swap(buffer_, rhs.buffer_);
        std::swap(size_, rhs.size_);
        std::swap(num_blocks_, rhs.num_blocks_);
        std::swap(head_, rhs.head_);
        std::swap(start_head_, rhs.start_head_);
        std::swap(tail_, rhs.tail_);
        std::swap(start_tail_, rhs.start_tail_);
    }

    void Realloc() {
        auto temp = std::make_unique<BlockPtr[]>(num_blocks_ * 2);
        for (size_t i = 0; i < ((head_ % 128 == 0) ? (0) : (1)) + head_ / 128; ++i) {
            temp[i] = buffer_[i];
        }
        for (size_t i = 0; i < ((tail_ % 128 == 0) ? (0) : (1)) + tail_ / 128; ++i) {
            temp[2 * num_blocks_ - 1 - i] = buffer_[num_blocks_ - 1 - i];
        }
        std::swap(buffer_, temp);
        num_blocks_ *= 2;
    }

    void PushBack(int value) {
        if (start_tail_ != 0) {
            (*buffer_[num_blocks_ - start_tail_ / 128 - 1])[(128 - start_tail_ % 128) % 128] =
                value;
            --start_tail_;
        } else {
            if (head_ % 128 != 0) {
                (*buffer_[head_ / 128])[head_ % 128] = value;
            } else if (((tail_ % 128 == 0) ? (0) : (1)) + tail_ / 128 + head_ / 128 < num_blocks_) {
                BlockPtr temp(new Block);
                buffer_[head_ / 128] = temp;
                (*buffer_[head_ / 128])[0] = value;
            } else {
                Realloc();
                BlockPtr temp(new Block);
                buffer_[head_ / 128] = temp;
                (*buffer_[head_ / 128])[0] = value;
            }
            ++head_;
        }
        ++size_;
    }

    void PopBack() {
        if (head_ == 0) {
            ++start_tail_;
        } else {
            --head_;
        }
        --size_;
    }

    void PushFront(int value) {
        if (start_head_ != 0) {
            (*buffer_[start_head_ / 128])[(start_head_ - 1) % 128] = value;
            --start_head_;
        } else {
            if (tail_ % 128 != 0) {
                (*buffer_[num_blocks_ - 1 - tail_ / 128])[128 - tail_ % 128 - 1] = value;
            } else if (((head_ % 128 == 0) ? (0) : (1)) + tail_ / 128 + head_ / 128 < num_blocks_) {
                BlockPtr temp(new Block);
                buffer_[num_blocks_ - tail_ / 128 - 1] = temp;
                (*buffer_[num_blocks_ - tail_ / 128 - 1])[127] = value;
            } else {
                Realloc();
                BlockPtr temp(new Block);
                buffer_[num_blocks_ - tail_ / 128 - 1] = temp;
                (*buffer_[num_blocks_ - tail_ / 128 - 1])[127] = value;
            }
            ++tail_;
        }
        ++size_;
    }
    void PopFront() {
        if (tail_ != 0) {
            --tail_;
        } else {
            ++start_head_;
        }
        --size_;
    }

    int& operator[](size_t ind) {
        if (ind < tail_ - start_tail_) {
            return (
                *buffer_[num_blocks_ - (tail_ - ind - 1) / 128 - 1])[127 - (tail_ - ind - 1) % 128];
        } else {
            ind -= tail_ - start_head_;
            return (*buffer_[ind / 128])[ind % 128];
        }
    }

    int operator[](size_t ind) const {
        if (ind < tail_ - start_tail_) {
            return (
                *buffer_[num_blocks_ - (tail_ - ind - 1) / 128 - 1])[127 - (tail_ - ind - 1) % 128];
        } else {
            ind -= tail_ - start_head_;
            return (*buffer_[ind / 128])[ind % 128];
        }
    }

    size_t Size() const {
        return size_;
    }

    void Clear() {
        size_ = 0;
        head_ = 0;
        start_head_ = 0;
        tail_ = 0;
        start_tail_ = 0;
    }

private:
    std::unique_ptr<std::shared_ptr<Block>[]> buffer_;
    size_t size_;
    size_t head_;
    size_t start_head_ = 0;
    size_t tail_;
    size_t start_tail_ = 0;
    size_t num_blocks_;
};
