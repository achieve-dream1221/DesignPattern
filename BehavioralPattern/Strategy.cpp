// @Time: 2024/10/30 17:19
// @Author: ACHIEVE_DREAM
// @File: Strategy.cpp
// @Software: CLion
#include <iostream>

// 策略接口
class Strategy {
public:
    virtual ~Strategy() = default;
    virtual void execute(int a, int b) const = 0;
};

// 具体策略：加法
class ConcreteStrategyAdd final : public Strategy {
public:
    void execute(const int a, const int b) const override {
        std::cout << "Result of addition: " << a + b << std::endl;
    }
};

// 具体策略：减法
class ConcreteStrategySubtract final : public Strategy {
public:
    void execute(const int a, const int b) const override {
        std::cout << "Result of subtraction: " << a - b << std::endl;
    }
};

// 上下文
class Context {
    std::shared_ptr<Strategy> strategy;

public:
    explicit Context(std::shared_ptr<Strategy> str) : strategy(std::move(str)) {}

    void setStrategy(std::shared_ptr<Strategy> str) {
        strategy = std::move(str);
    }

    void executeStrategy(const int a, const int b) const {
        strategy->execute(a, b);
    }
};

int main() {
    Context context(std::make_shared<ConcreteStrategyAdd>());
    context.executeStrategy(5, 3);  // 输出：Result of addition: 8

    context.setStrategy(std::make_shared<ConcreteStrategySubtract>());
    context.executeStrategy(5, 3);  // 输出：Result of subtraction: 2

    return 0;
}
