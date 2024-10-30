// @Time: 2024/10/30 17:17
// @Author: ACHIEVE_DREAM
// @File: NullObject.cpp
// @Software: CLion
#include <iostream>
#include <utility>

// 抽象角色
class AbstractProduct {
public:
    virtual ~AbstractProduct() = default;
    virtual void doSomething() const = 0;
};

// 具体角色：真实产品
class RealProduct final : public AbstractProduct {
public:
    void doSomething() const override {
        std::cout << "Real product doing something." << std::endl;
    }
};

// 具体角色：空对象
class NullProduct final : public AbstractProduct {
public:
    void doSomething() const override {
        // 不做任何事情
    }
};

// 客户端
class Client {
    std::shared_ptr<AbstractProduct> product;

public:
    explicit Client(std::shared_ptr<AbstractProduct> p) : product(std::move(p)) {}

    void execute() const {
        product->doSomething();
    }
};

int main() {
    const std::shared_ptr<AbstractProduct> realProduct = std::make_shared<RealProduct>();
    const std::shared_ptr<AbstractProduct> nullProduct = std::make_shared<NullProduct>();

    const Client client1(realProduct);
    const Client client2(nullProduct);

    client1.execute();  // 输出：Real product doing something.
    client2.execute();  // 不输出任何内容

    return 0;
}
