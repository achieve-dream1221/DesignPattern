// @Time: 2024/10/30 16:07
// @Author: ACHIEVE_DREAM
// @File: Decorator.cpp
// @Software: CLion
#include <iostream>
#include <memory>
#include <utility>

// 基础组件
class Coffee {
public:
    virtual ~Coffee() = default;
    [[nodiscard]] virtual std::string getDescription() const {
        return "Coffee";
    }
    [[nodiscard]] virtual double cost() const {
        return 2.0;
    }
};

// 装饰器基类
class CoffeeDecorator : public Coffee {
protected:
    std::shared_ptr<Coffee> coffee;
public:
    explicit CoffeeDecorator(std::shared_ptr<Coffee> c) : coffee(std::move(c)) {}
};

// 牛奶装饰器
class MilkDecorator : public CoffeeDecorator {
public:
    using CoffeeDecorator::CoffeeDecorator;
    [[nodiscard]] std::string getDescription() const override {
        return coffee->getDescription() + ", Milk";
    }

    [[nodiscard]] double cost() const override {
        return coffee->cost() + 0.5;
    }
};

// 糖装饰器
class SugarDecorator final : public CoffeeDecorator {
public:
    using CoffeeDecorator::CoffeeDecorator;

    [[nodiscard]] std::string getDescription() const override {
        return coffee->getDescription() + ", Sugar";
    }

    [[nodiscard]] double cost() const override {
        return coffee->cost() + 0.2;
    }
};

int main() {
    auto myCoffee = std::make_shared<Coffee>();
    myCoffee = std::make_shared<MilkDecorator>(myCoffee);
    myCoffee = std::make_shared<SugarDecorator>(myCoffee);

    std::cout << myCoffee->getDescription() << " costs " << myCoffee->cost() << std::endl;
    return 0;
}
