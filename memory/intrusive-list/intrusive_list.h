#pragma once

#include <algorithm>

class ListHook {
public:
    ListHook() : prev_(this), next_(this) {
    }

    bool IsLinked() const {
        return prev_ != this || next_ != this;
    }

    void Unlink() {
        if (prev_ != nullptr) {
            prev_->next_ = next_;
        }
        if (next_ != nullptr) {
            next_->prev_ = prev_;
        }
        next_ = prev_ = this;
    }

    // Must unlink element from list
    ~ListHook() {
        Unlink();
    }

    ListHook(const ListHook&) = delete;

private:
    template <class T>
    friend class List;
    ListHook* prev_;
    ListHook* next_;
    // that helper function might be useful
    void LinkBefore(ListHook* other) {
        other->prev_->next_ = this;
        prev_ = other->prev_;
        other->prev_ = this;
        next_ = other;
    }
};

template <typename T>
class List {
public:
    class Iterator : public std::iterator<std::bidirectional_iterator_tag, T> {
    public:
        Iterator() {
            data_ = nullptr;
        }
        Iterator(ListHook* data) : data_(data) {
        }
        ~Iterator() = default;

        Iterator& operator++() {
            data_ = data_->next_;
            return *this;
        }
        Iterator operator++(int) {
            Iterator temporary(*this);
            ++*this;
            return temporary;
        };

        T& operator*() const {
            return *static_cast<T*>(data_);
        }
        T* operator->() const {
            return static_cast<T*>(data_);
        };

        bool operator==(const Iterator& rhs) const {
            return data_ == rhs.data_;
        };
        bool operator!=(const Iterator& rhs) const {
            return data_ != rhs.data_;
        }

    private:
        ListHook* data_;
    };

    List() {
    }
    List(const List&) = delete;
    List(List&& other) {
        (&dummy_)->LinkBefore(other.dummy_.next_);
        other.dummy_.Unlink();
    }

    // must unlink all elements from list
    ~List() {
        ListHook* current = dummy_.next_;
        while (current != &dummy_) {
            ListHook* next = current->next_;
            current->Unlink();
            current = next;
        }
    }

    List& operator=(const List&) = delete;
    List& operator=(List&& other) {
        if (&dummy_ == &other.dummy_) {
            return *this;
        }

        ListHook* current = dummy_.next_;
        while (current != &dummy_) {
            ListHook* next = current->next_;
            current->Unlink();
            current = next;
        }
        (&dummy_)->LinkBefore(other.dummy_.next_);
        other.dummy_.Unlink();
        return *this;
    }

    bool IsEmpty() const {
        return dummy_.next_ == &dummy_;
    }
    // that method is allowed to be O(n)
    size_t Size() const {
        size_t size = 0;
        ListHook* current = dummy_.next_;
        while (current != &dummy_) {
            current = current->next_;
            ++size;
        }
        return size;
    }

    // note that IntrusiveList doesn't own elements,
    // and never copies or moves T
    void PushBack(T* elem) {
        elem->LinkBefore(&dummy_);
    }
    void PushFront(T* elem) {
        elem->LinkBefore(dummy_.next_);
    }

    T& Front() {
        return *static_cast<T*>(dummy_.next_);
    }
    const T& Front() const {
        return *static_cast<T*>(dummy_.next_);
    }

    T& Back() {
        return *static_cast<T*>(dummy_.prev_);
    }
    const T& Back() const {
        return *static_cast<T*>(dummy_.prev_);
    }

    void PopBack() {
        dummy_.prev_->Unlink();
    }
    void PopFront() {
        dummy_.next_->Unlink();
    }

    Iterator Begin() {
        return Iterator(dummy_.next_);
    }
    Iterator End() {
        return Iterator(&dummy_);
    }

    // complexity of this function must be O(1)
    Iterator IteratorTo(T* element) {
        return Iterator(element);
    }

private:
    ListHook dummy_;
};

template <typename T>
typename List<T>::Iterator begin(List<T>& list) {  // NOLINT
    return list.Begin();
}

template <typename T>
typename List<T>::Iterator end(List<T>& list) {  // NOLINT
    return list.End();
}
