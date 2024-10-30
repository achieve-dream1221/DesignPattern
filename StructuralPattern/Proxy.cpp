// @Time: 2024/10/30 16:34
// @Author: ACHIEVE_DREAM
// @File: Proxy.cpp
// @Software: CLion
#include <iostream>
#include <memory>

// 抽象主题
class Subject {
public:
    virtual ~Subject() = default;
    virtual void request() const = 0;
};

// 真实主题
class RealSubject final : public Subject {
public:
    void request() const override {
        std::cout << "RealSubject: Handling request." << std::endl;
    }
};

// 代理
class Proxy final : public Subject {
    std::shared_ptr<RealSubject> realSubject;

public:
    Proxy() : realSubject(std::make_shared<RealSubject>()) {}

    void request() const override {
        std::cout << "Proxy: Pre-processing request." << std::endl;
        realSubject->request();
        std::cout << "Proxy: Post-processing request." << std::endl;
    }
};

int main() {
    const std::shared_ptr<Subject> proxy = std::make_shared<Proxy>();
    proxy->request();

    return 0;
}
