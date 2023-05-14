#pragma once

#include <list>
#include <string>
#include <memory>
#include <utility>

class Command {
public:
    virtual std::shared_ptr<Command> OppositeCommand() = 0;
    virtual ~Command() = default;
};

class TypeCommand : public Command {
public:
    TypeCommand(char cc) : c(cc) {
    }
    std::shared_ptr<Command> OppositeCommand() override;

public:
    char c;
};

class BackSpace : public Command {
public:
    BackSpace() {
    }
    BackSpace(char cc) : c(cc) {
    }
    std::shared_ptr<Command> OppositeCommand() override {
        return std::make_shared<TypeCommand>(c);
    }

public:
    char c;
};

class Shift : public Command {
public:
    Shift(int val) : dir(val){};

    std::shared_ptr<Command> OppositeCommand() override {
        return std::make_shared<Shift>(-dir);
    }

public:
    int dir;
};

std::shared_ptr<Command> TypeCommand::OppositeCommand() {
    return std::make_shared<BackSpace>(c);
}

class EditorHelper {
public:
    EditorHelper() {
        text_iterator_ = text_.begin();
        history_iterator_ = history_.end();
    }

    const std::string &GetText() const {
        return text_;
    }
    void Apply(const std::shared_ptr<Command> &command) {
        history_iterator_ = history_.end();
        if (ApplyCommand(command)) {
            history_.push_back(command);
        }
    }

    void Undo() {
        if (history_iterator_ != history_.begin()) {
            --history_iterator_;
            ApplyCommand((*history_iterator_)->OppositeCommand());
        }
    }

    void Redo() {
        if (history_iterator_ != history_.end()) {
            ApplyCommand(*history_iterator_);
            ++history_iterator_;
        }
    }

private:
    bool ApplyCommand(const std::shared_ptr<Command> &ptr) {
        bool flag = false;
        if (std::dynamic_pointer_cast<Shift>(ptr)) {
            std::shared_ptr<Shift> mod_ptr = std::dynamic_pointer_cast<Shift>(ptr);
            if (mod_ptr->dir == 1 && text_.end() - text_iterator_ >= 1) {
                text_iterator_ += mod_ptr->dir;
                flag = true;
            }
            if (mod_ptr->dir == -1 && text_iterator_ - text_.begin() >= 1) {
                text_iterator_ += mod_ptr->dir;
                flag = true;
            }
        } else if (std::dynamic_pointer_cast<BackSpace>(ptr)) {
            std::shared_ptr<BackSpace> mod_ptr = std::dynamic_pointer_cast<BackSpace>(ptr);
            if (text_iterator_ != text_.begin()) {
                mod_ptr->c = *(--text_iterator_);
                text_iterator_ = text_.erase(text_iterator_);
                flag = true;
            }
        } else if (std::dynamic_pointer_cast<TypeCommand>(ptr)) {
            std::shared_ptr<TypeCommand> mod_ptr = std::dynamic_pointer_cast<TypeCommand>(ptr);
            text_iterator_ = ++text_.insert(text_iterator_, mod_ptr->c);
            flag = true;
        }
        return flag;
    }

private:
    std::string text_;
    std::list<std::shared_ptr<Command>> history_;
    std::string::iterator text_iterator_;
    std::list<std::shared_ptr<Command>>::iterator history_iterator_;
};

class Editor {
public:
    const std::string &GetText() const {
        return edit_.GetText();
    }

    void Type(char c) {
        edit_.Apply(std::make_shared<TypeCommand>(c));
    }

    void ShiftLeft() {
        edit_.Apply(std::make_shared<Shift>(-1));
    }

    void ShiftRight() {
        edit_.Apply(std::make_shared<Shift>(1));
    }

    void Backspace() {
        edit_.Apply(std::make_shared<BackSpace>());
    }

    void Undo() {
        edit_.Undo();
    }

    void Redo() {
        edit_.Redo();
    }

private:
    EditorHelper edit_;
};