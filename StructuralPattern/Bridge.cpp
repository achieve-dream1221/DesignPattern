// @Time: 2024/10/29 16:45
// @Author: ACHIEVE_DREAM
// @File: Bridge.cpp
// @Software: CLion
#include <iostream>

// 实现部分接口
class Implementor {
public:
    virtual void operationImpl() const = 0;

    virtual ~Implementor() = default;
};

// 具体实现 A
class ConcreteImplementorA final : public Implementor {
public:
    void operationImpl() const override {
        std::cout << "ConcreteImplementorA: 实现 A 的操作。" << std::endl;
    }
};

// 具体实现 B
class ConcreteImplementorB final : public Implementor {
public:
    void operationImpl() const override {
        std::cout << "ConcreteImplementorB: 实现 B 的操作。" << std::endl;
    }
};

// 抽象部分
class Abstraction {
protected:
    Implementor *implementor_;

public:
    explicit Abstraction(Implementor *implementor) : implementor_(implementor) {
    }

    virtual void operation() const = 0;

    virtual ~Abstraction() = default;
};

// 扩展抽象部分
class RefinedAbstraction final : public Abstraction {
public:
    using Abstraction::Abstraction; // 继承构造函数

    void operation() const override {
        std::cout << "RefinedAbstraction: 扩展抽象部分调用 -> ";
        implementor_->operationImpl();
    }
};

int main() {
    Implementor *implementorA = new ConcreteImplementorA();
    Implementor *implementorB = new ConcreteImplementorB();

    const Abstraction *abstractionA = new RefinedAbstraction(implementorA);
    const Abstraction *abstractionB = new RefinedAbstraction(implementorB);

    abstractionA->operation();
    abstractionB->operation();

    delete implementorA;
    delete implementorB;
    delete abstractionA;
    delete abstractionB;

    return 0;
}
