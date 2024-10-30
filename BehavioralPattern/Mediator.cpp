// @Time: 2024/10/30 17:01
// @Author: ACHIEVE_DREAM
// @File: Mediator.cpp
// @Software: CLion
#include <iostream>
#include <string>

// 抽象中介者
class Mediator;

// 同事类
class Colleague {
protected:
    Mediator* mediator;

public:
    explicit Colleague(Mediator* med) : mediator(med) {}
    virtual ~Colleague() = default;
    virtual void send(const std::string& message) = 0;
    virtual void receive(const std::string& message) = 0;
};

// 中介者接口
class Mediator {
public:
    virtual ~Mediator() = default;
    virtual void notify(Colleague* colleague, const std::string& message) = 0;
};

// 具体中介者
class ConcreteMediator final : public Mediator {
    Colleague* colleague1{};
    Colleague* colleague2{};

public:
    void setColleagues(Colleague* c1, Colleague* c2) {
        colleague1 = c1;
        colleague2 = c2;
    }

    void notify(Colleague* colleague, const std::string& message) override {
        if (colleague == colleague1) {
            colleague2->receive(message);
        } else {
            colleague1->receive(message);
        }
    }
};

// 具体同事类 A
class ConcreteColleagueA final : public Colleague {
public:
    using Colleague::Colleague;

    void send(const std::string& message) override {
        std::cout << "Colleague A sending: " << message << std::endl;
        mediator->notify(this, message);
    }

    void receive(const std::string& message) override {
        std::cout << "Colleague A received: " << message << std::endl;
    }
};

// 具体同事类 B
class ConcreteColleagueB final : public Colleague {
public:
    using Colleague::Colleague;

    void send(const std::string& message) override {
        std::cout << "Colleague B sending: " << message << std::endl;
        mediator->notify(this, message);
    }

    void receive(const std::string& message) override {
        std::cout << "Colleague B received: " << message << std::endl;
    }
};

int main() {
    ConcreteMediator mediator;
    ConcreteColleagueA colleagueA(&mediator);
    ConcreteColleagueB colleagueB(&mediator);

    mediator.setColleagues(&colleagueA, &colleagueB);

    colleagueA.send("Hello from A");
    colleagueB.send("Hello from B");
    return 0;
}
