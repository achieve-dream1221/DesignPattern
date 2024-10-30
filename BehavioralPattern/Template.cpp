// @Time: 2024/10/30 17:22
// @Author: ACHIEVE_DREAM
// @File: Template.cpp
// @Software: CLion
#include <iostream>

// 抽象类
class AbstractClass {
public:
    virtual ~AbstractClass() = default;

    // 模板方法
    void templateMethod() const {
        stepOne();
        stepTwo();
        stepThree();
    }

protected:
    virtual void stepOne() const = 0;
    virtual void stepTwo() const = 0;

    // 钩子方法
    virtual void stepThree() const {
        std::cout << "Default implementation of step three." << std::endl;
    }
};

// 具体类 A
class ConcreteClassA final : public AbstractClass {
protected:
    void stepOne() const override {
        std::cout << "ConcreteClassA: Step One" << std::endl;
    }

    void stepTwo() const override {
        std::cout << "ConcreteClassA: Step Two" << std::endl;
    }
};

// 具体类 B
class ConcreteClassB final : public AbstractClass {
protected:
    void stepOne() const override {
        std::cout << "ConcreteClassB: Step One" << std::endl;
    }

    void stepTwo() const override {
        std::cout << "ConcreteClassB: Step Two" << std::endl;
    }

    void stepThree() const override {
        std::cout << "ConcreteClassB: Custom implementation of step three." << std::endl;
    }
};

int main() {
    const auto classA = std::make_shared<ConcreteClassA>();
    classA->templateMethod();

    std::cout << std::endl;

    const auto classB = std::make_shared<ConcreteClassB>();
    classB->templateMethod();

    return 0;
}
