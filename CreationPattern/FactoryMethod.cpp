// @Time: 2024/10/29 14:41
// @Author: ACHIEVE_DREAM
// @File: FactoryMethod.cpp
// @Software: CLion
#include <iostream>
#include <memory>

// 产品接口
class Product {
public:
    virtual void use() const = 0; // 定义产品的接口方法
    virtual ~Product() = default;
};

// 具体产品A
class ConcreteProductA final : public Product {
public:
    void use() const override {
        std::cout << "使用产品A\n";
    }
};

// 具体产品B
class ConcreteProductB final : public Product {
public:
    void use() const override {
        std::cout << "使用产品B\n";
    }
};

// 工厂接口
class Factory {
public:
    [[nodiscard]] virtual std::unique_ptr<Product> createProduct() const = 0;

    virtual ~Factory() = default;
};

// 具体工厂A
class ConcreteFactoryA final : public Factory {
public:
    [[nodiscard]] std::unique_ptr<Product> createProduct() const override {
        return std::make_unique<ConcreteProductA>();
    }
};

// 具体工厂B
class ConcreteFactoryB final : public Factory {
public:
    [[nodiscard]] std::unique_ptr<Product> createProduct() const override {
        return std::make_unique<ConcreteProductB>();
    }
};

int main() {
    const auto factoryA = std::make_unique<ConcreteFactoryA>();
    const auto factoryB = std::make_unique<ConcreteFactoryB>();

    const auto productA = factoryA->createProduct();
    productA->use();

    const auto productB = factoryB->createProduct();
    productB->use();

    return 0;
}
