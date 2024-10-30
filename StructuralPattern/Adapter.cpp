// @Time: 2024/10/29 16:35
// @Author: ACHIEVE_DREAM
// @File: Adapter.cpp
// @Software: CLion

#include <iostream>

// 类适配器
class Target {
public:
    virtual ~Target() = default;

    virtual void request() const {
        std::cout << "Target: Default target's behavior." << std::endl;
    }
};

// 被适配的类
class Adaptee {
public:
    static void specificRequest() {
        std::cout << "Adaptee: Specific behavior." << std::endl;
    }
};

class Adapter final : public Target, Adaptee {
public:
    void request() const override {
        specificRequest();
    }
};

int main() {
    const Target *target = new Adapter();
    target->request();
    delete target;
    return 0;
}


/*
 *对象适配器
#include <iostream>

// 目标接口
class Target {
public:
    virtual ~Target() = default;

    virtual void request() const {
        std::cout << "Target: Default target's behavior." << std::endl;
    }
};

// 被适配的类
class Adaptee {
public:
    static void specificRequest() {
        std::cout << "Adaptee: Specific behavior." << std::endl;
    }
};

// 适配器类
class Adapter final : public Target {
    Adaptee *adaptee_;

public:
    explicit Adapter(Adaptee *adaptee) : adaptee_(adaptee) {
    }

    void request() const override {
        Adaptee::specificRequest();
    }
};

int main() {
    auto *adaptee = new Adaptee;
    const Target *target = new Adapter(adaptee);
    target->request();

    delete adaptee;
    delete target;
    return 0;
}
*/
