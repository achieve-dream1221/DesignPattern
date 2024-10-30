// @Time: 2024/10/30 17:05
// @Author: ACHIEVE_DREAM
// @File: Memento.cpp
// @Software: CLion
#include <iostream>
#include <memory>
#include <string>
#include <utility>

// 备忘录类
class Memento {
    std::string state;

public:
    explicit Memento(std::string  state) : state(std::move(state)) {}

    [[nodiscard]] std::string getState() const {
        return state;
    }
};

// 发起人类
class Originator {
    std::string state;

public:
    void setState(const std::string& state) {
        this->state = state;
    }

    [[nodiscard]] std::string getState() const {
        return state;
    }

    std::shared_ptr<Memento> saveStateToMemento() {
        return std::make_shared<Memento>(state);
    }

    void getStateFromMemento(const std::shared_ptr<Memento>& memento) {
        state = memento->getState();
    }
};

// 管理者类
class Caretaker {
    std::shared_ptr<Memento> memento;

public:
    void saveState(Originator& originator) {
        memento = originator.saveStateToMemento();
    }

    void restoreState(Originator& originator) const {
        if (memento) {
            originator.getStateFromMemento(memento);
        }
    }
};

int main() {
    Originator originator;
    Caretaker caretaker;

    originator.setState("State1");
    caretaker.saveState(originator);

    originator.setState("State2");
    std::cout << "Current State: " << originator.getState() << std::endl;

    caretaker.restoreState(originator);
    std::cout << "Restored State: " << originator.getState() << std::endl;

    return 0;
}
