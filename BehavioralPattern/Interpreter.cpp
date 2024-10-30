// @Time: 2024/10/30 16:51
// @Author: ACHIEVE_DREAM
// @File: Interpreter.cpp
// @Software: CLion
#include <iostream>
#include <memory>
#include <string>
#include <unordered_map>
#include <utility>

// 抽象表达式
class Expression {
public:
    virtual ~Expression() = default;
    [[nodiscard]] virtual int interpret(const std::unordered_map<std::string, int>& context) const = 0;
};

// 终结符表达式：变量
class Variable final : public Expression {
    std::string name;

public:
    explicit Variable(std::string  n) : name(std::move(n)) {}

    [[nodiscard]] int interpret(const std::unordered_map<std::string, int>& context) const override {
        return context.at(name);
    }
};

// 终结符表达式：常量
class Number final : public Expression {
    int number;

public:
    explicit Number(const int n) : number(n) {}

    [[nodiscard]] int interpret(const std::unordered_map<std::string, int>&) const override {
        return number;
    }
};

// 非终结符表达式：加法
class Addition final : public Expression {
    std::shared_ptr<Expression> left;
    std::shared_ptr<Expression> right;

public:
    Addition(std::shared_ptr<Expression> l, std::shared_ptr<Expression> r)
        : left(std::move(l)), right(std::move(r)) {}

    [[nodiscard]] int interpret(const std::unordered_map<std::string, int>& context) const override {
        return left->interpret(context) + right->interpret(context);
    }
};

// 客户端
int main() {
    // 上下文：变量的值
    std::unordered_map<std::string, int> context;
    context["x"] = 5;
    context["y"] = 10;

    // 表达式：x + y
    std::shared_ptr<Expression> x = std::make_shared<Variable>("x");
    std::shared_ptr<Expression> y = std::make_shared<Variable>("y");
    const std::shared_ptr<Expression> addition = std::make_shared<Addition>(x, y);

    std::cout << "Result: " << addition->interpret(context) << std::endl;  // 输出：Result: 15

    return 0;
}
