#include <huffman.h>
#include <optional>
#include <numeric>

class HuffmanTree::Impl {
public:
    struct Node {
        std::optional<uint8_t> value;
        std::shared_ptr<Node> left;
        std::shared_ptr<Node> right;
        std::weak_ptr<Node> parent;
    };
    std::shared_ptr<Node> root_;
    std::shared_ptr<Node> current_;
};

void HuffmanTree::Build(const std::vector<uint8_t> &code_lengths,
                        const std::vector<uint8_t> &values) {
    if (code_lengths.size() > 16) {
        throw std::invalid_argument("code length > 16");
    }
    if (static_cast<size_t>(std::accumulate(code_lengths.begin(), code_lengths.end(), 0)) !=
        values.size()) {
        throw std::invalid_argument("the number of places does not match the number of values");
    }
    impl_->root_ = std::make_shared<Impl::Node>();
    impl_->current_ = impl_->root_;
    if (values.empty()) {
        return;
    }
    std::vector<uint8_t> size_leafs = code_lengths;
    size_t depth = 0;
    // for the first value
    do {
        impl_->current_->left = std::make_shared<Impl::Node>();
        impl_->current_->left->parent = impl_->current_;
        impl_->current_ = impl_->current_->left;
    } while (size_leafs[depth++] == 0);
    impl_->current_->value = values[0];
    --size_leafs[--depth];
    // for others values
    for (size_t idx_value = 1; idx_value < values.size(); ++idx_value) {
        // looking for a parent without the right child
        while (impl_->current_->parent.lock()->right) {
            impl_->current_ = impl_->current_->parent.lock();
            --depth;
            if (impl_->current_ == impl_->root_) {
                throw std::invalid_argument("wrong vector code_length");
            }
        }
        // if found, go to it
        impl_->current_->parent.lock()->right = std::make_shared<Impl::Node>();
        impl_->current_->parent.lock()->right->parent = impl_->current_->parent.lock();
        impl_->current_ = impl_->current_->parent.lock()->right;
        // like first value
        while (size_leafs[depth] == 0) {
            impl_->current_->left = std::make_shared<Impl::Node>();
            impl_->current_->left->parent = impl_->current_;
            impl_->current_ = impl_->current_->left;
            ++depth;
        }
        impl_->current_->value = values[idx_value];
        --size_leafs[depth];
    }
    impl_->current_ = impl_->root_;
}

bool HuffmanTree::Move(bool bit, int &value) {
    if (!impl_->root_) {
        throw std::invalid_argument("tree didn't build");
    }
    if (!impl_->current_) {
        throw std::invalid_argument("something goes wrong in move with current node");
    }
    if (bit == 0) {
        if (!impl_->current_->left) {
            throw std::invalid_argument("not possible to go to the left");
        }
        impl_->current_ = impl_->current_->left;
    }
    if (bit == 1) {
        if (!impl_->current_->right) {
            throw std::invalid_argument("not possible to go to the right");
        }
        impl_->current_ = impl_->current_->right;
    }
    if (impl_->current_->value) {
        value = impl_->current_->value.value();
        impl_->current_ = impl_->root_;
        return true;
    } else {
        return false;
    }
}

HuffmanTree::HuffmanTree() {
    impl_ = std::make_unique<Impl>();
};

HuffmanTree::HuffmanTree(HuffmanTree &&) = default;

HuffmanTree &HuffmanTree::operator=(HuffmanTree &&) = default;

HuffmanTree::~HuffmanTree() = default;
