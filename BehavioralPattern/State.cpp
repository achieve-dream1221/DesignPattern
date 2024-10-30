// @Time: 2024/10/30 17:14
// @Author: ACHIEVE_DREAM
// @File: State.cpp
// @Software: CLion
#include <iostream>

// 抽象状态
class State {
public:
    virtual ~State() = default;
    virtual void handle() = 0;
};

// 具体状态 A
class ConcreteStateA final : public State {
public:
    void handle() override {
        std::cout << "Handling state A." << std::endl;
    }
};

// 具体状态 B
class ConcreteStateB final : public State {
public:
    void handle() override {
        std::cout << "Handling state B." << std::endl;
    }
};

// 上下文类
class Context {
    std::shared_ptr<State> state;

public:
    void setState(const std::shared_ptr<State> &newState) {
        state = newState;
    }

    void request() const {
        if (state) {
            state->handle();
        } else {
            std::cout << "No state set." << std::endl;
        }
    }
};

int main() {
    Context context;

    const auto stateA = std::make_shared<ConcreteStateA>();
    const auto stateB = std::make_shared<ConcreteStateB>();

    context.setState(stateA);
    context.request();  // 输出：Handling state A.

    context.setState(stateB);
    context.request();  // 输出：Handling state B.

    return 0;
}
