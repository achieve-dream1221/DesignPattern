// @Time: 2024/10/30 16:38
// @Author: ACHIEVE_DREAM
// @File: ChainOfResponsibility.cpp
// @Software: CLion
#include <iostream>
#include <memory>

// 抽象处理者
class Handler {
protected:
    std::shared_ptr<Handler> nextHandler;

public:
    virtual ~Handler() = default;

    void setNext(const std::shared_ptr<Handler> &handler) {
        nextHandler = handler;
    }

    virtual void handleRequest(const int request) {
        if (nextHandler) {
            nextHandler->handleRequest(request);
        }
    }
};

// 具体处理者 A
class ConcreteHandlerA final : public Handler {
public:
    void handleRequest(const int request) override {
        if (request == 1) {
            std::cout << "Handler A handling request " << request << std::endl;
        } else {
            Handler::handleRequest(request);
        }
    }
};

// 具体处理者 B
class ConcreteHandlerB final : public Handler {
public:
    void handleRequest(const int request) override {
        if (request == 2) {
            std::cout << "Handler B handling request " << request << std::endl;
        } else {
            Handler::handleRequest(request);
        }
    }
};

// 具体处理者 C
class ConcreteHandlerC final : public Handler {
public:
    void handleRequest(const int request) override {
        if (request == 3) {
            std::cout << "Handler C handling request " << request << std::endl;
        } else {
            Handler::handleRequest(request);
        }
    }
};

int main() {
    const auto handlerA = std::make_shared<ConcreteHandlerA>();
    const auto handlerB = std::make_shared<ConcreteHandlerB>();
    const auto handlerC = std::make_shared<ConcreteHandlerC>();

    handlerA->setNext(handlerB);
    handlerB->setNext(handlerC);

    // 处理请求
    handlerA->handleRequest(1);
    handlerA->handleRequest(2);
    handlerA->handleRequest(3);
    handlerA->handleRequest(4);  // 未处理的请求

    return 0;
}
