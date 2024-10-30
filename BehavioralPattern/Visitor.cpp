// @Time: 2024/10/30 17:25
// @Author: ACHIEVE_DREAM
// @File: Visitor.cpp
// @Software: CLion
#include <iostream>
#include <vector>

// 前向声明
class ElementA;
class ElementB;

// 访问者接口
class Visitor {
public:
    virtual ~Visitor() = default;
    virtual void visit(ElementA& element) = 0;
    virtual void visit(ElementB& element) = 0;
};

// 抽象元素接口
class Element {
public:
    virtual ~Element() = default;
    virtual void accept(Visitor& visitor) = 0;
};

// 具体元素 A
class ElementA final : public Element {
public:
    void accept(Visitor& visitor) override {
        visitor.visit(*this);
    }

    static void operationA() {
        std::cout << "Element A operation." << std::endl;
    }
};

// 具体元素 B
class ElementB final : public Element {
public:
    void accept(Visitor& visitor) override {
        visitor.visit(*this);
    }

    static void operationB() {
        std::cout << "Element B operation." << std::endl;
    }
};

// 具体访问者
class ConcreteVisitor final : public Visitor {
public:
    void visit(ElementA& element) override {
        std::cout << "Visiting Element A." << std::endl;
        ElementA::operationA();
    }

    void visit(ElementB& element) override {
        std::cout << "Visiting Element B." << std::endl;
        ElementB::operationB();
    }
};

// 客户端
int main() {
    std::vector<std::shared_ptr<Element>> elements;
    elements.emplace_back(std::make_shared<ElementA>());
    elements.emplace_back(std::make_shared<ElementB>());

    ConcreteVisitor visitor;

    for (const auto& element : elements) {
        element->accept(visitor);
    }

    return 0;
}
