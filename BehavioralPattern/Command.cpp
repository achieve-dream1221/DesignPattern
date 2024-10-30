// @Time: 2024/10/30 16:48
// @Author: ACHIEVE_DREAM
// @File: Command.cpp
// @Software: CLion
#include <iostream>
#include <memory>
#include <vector>

// 命令接口
class Command {
public:
    virtual ~Command() = default;
    virtual void execute() const = 0;
};

// 具体命令：打开命令
class OpenCommand final : public Command {
public:
    void execute() const override {
        std::cout << "Opening the document." << std::endl;
    }
};

// 具体命令：保存命令
class SaveCommand final : public Command {
public:
    void execute() const override {
        std::cout << "Saving the document." << std::endl;
    }
};

// 具体命令：关闭命令
class CloseCommand final : public Command {
public:
    void execute() const override {
        std::cout << "Closing the document." << std::endl;
    }
};

// 调用者
class Invoker {
    std::vector<std::shared_ptr<Command>> commands;

public:
    void addCommand(const std::shared_ptr<Command>& command) {
        commands.push_back(command);
    }

    void executeCommands() const {
        for (const auto& command : commands) {
            command->execute();
        }
    }
};

int main() {
    Invoker invoker;
    invoker.addCommand(std::make_shared<OpenCommand>());
    invoker.addCommand(std::make_shared<SaveCommand>());
    invoker.addCommand(std::make_shared<CloseCommand>());

    invoker.executeCommands();

    return 0;
}
