// @Time: 2024/10/30 17:09
// @Author: ACHIEVE_DREAM
// @File: Observer.cpp
// @Software: CLion
#include <iostream>
#include <vector>

// 抽象观察者
class Observer {
public:
    virtual ~Observer() = default;
    virtual void update(int state) = 0;
};

// 抽象主题
class Subject {
public:
    virtual ~Subject() = default;
    virtual void attach(std::shared_ptr<Observer> observer) = 0;
    virtual void detach(std::shared_ptr<Observer> observer) = 0;
    virtual void notify() = 0;
};

// 具体主题
class ConcreteSubject final : public Subject {
    std::vector<std::shared_ptr<Observer>> observers;
    int state{};

public:
    void attach(const std::shared_ptr<Observer> observer) override {
        observers.emplace_back(observer);
    }

    void detach(const std::shared_ptr<Observer> observer) override {
        std::erase(observers, observer);
    }

    void setState(const int newState) {
        state = newState;
        notify();
    }

    void notify() override {
        for (const auto& observer : observers) {
            observer->update(state);
        }
    }
};

// 具体观察者
class ConcreteObserver final : public Observer {
    std::string name;

public:
    explicit ConcreteObserver(std::string  name) : name(std::move(name)) {}

    void update(const int state) override {
        std::cout << "Observer " << name << " received update: " << state << std::endl;
    }
};

int main() {
    const auto subject = std::make_shared<ConcreteSubject>();

    const auto observer1 = std::make_shared<ConcreteObserver>("A");
    const auto observer2 = std::make_shared<ConcreteObserver>("B");

    subject->attach(observer1);
    subject->attach(observer2);

    subject->setState(10);
    subject->detach(observer1);
    subject->setState(20);

    return 0;
}
