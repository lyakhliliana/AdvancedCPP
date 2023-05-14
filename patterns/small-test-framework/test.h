#pragma once

#include <exception>
#include <map>
#include <memory>
#include <string>
#include <vector>
#include <utility>
#include <functional>

class AbstractTest {
public:
    virtual void SetUp() = 0;
    virtual void TearDown() = 0;
    virtual void Run() = 0;
    virtual ~AbstractTest() {
    }
};

class Holder {
public:
    template <typename T>
    Holder(T&& f) : func_(std::move(f)) {
    }
    std::unique_ptr<AbstractTest> CreateTest() {
        test_ = func_();
        return std::move(test_);
    }

private:
    std::unique_ptr<AbstractTest> test_;
    std::function<std::unique_ptr<AbstractTest>()> func_;
};

class TestRegistry {
public:
    template <class TestClass>
    void RegisterClass(const std::string& class_name) {
        auto func = []() {
            std::unique_ptr<AbstractTest> ptr = std::make_unique<TestClass>();
            return std::move(ptr);
        };
        tests_.emplace(class_name, Holder(func));
    }

    std::unique_ptr<AbstractTest> CreateTest(const std::string& class_name) {
        auto it_test = tests_.find(class_name);
        if (it_test == tests_.end()) {
            throw std::out_of_range("");
        }
        return it_test->second.CreateTest();
    }

    void RunTest(const std::string& test_name) {
        std::unique_ptr<AbstractTest> test = CreateTest(test_name);
        test->SetUp();
        try {
            test->Run();
        } catch (...) {
            test->TearDown();
            throw;
        }
        test->TearDown();
    }

    template <class Predicate>
    std::vector<std::string> ShowTests(Predicate callback) const {
        std::vector<std::string> result;
        for (const auto& test : tests_) {
            if (callback(test.first)) {
                result.push_back(test.first);
            }
        }
        return result;
    }

    std::vector<std::string> ShowAllTests() const {
        return ShowTests([](const std::string&) { return true; });
    }

    template <class Predicate>
    void RunTests(Predicate callback) {
        for (const auto& test : tests_) {
            if (callback(test.first)) {
                RunTest(test.first);
            }
        }
    }

    void Clear() {
        tests_.clear();
    }

    static TestRegistry& Instance() {
        static TestRegistry tr;
        return tr;
    }

private:
    std::map<std::string, Holder> tests_;
};

auto Substr(const std::string& str) {
    return [&str](const std::string& string) { return string.find(str) != std::string::npos; };
}

auto FullMatch(const std::string& str) {
    return [&str](const std::string& string) { return string == str; };
}