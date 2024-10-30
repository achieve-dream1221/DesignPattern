// @Time: 2024/10/30 16:30
// @Author: ACHIEVE_DREAM
// @File: Flyweight.cpp
// @Software: CLion
#include <iostream>
#include <unordered_map>
#include <memory>

// 享元类
class Character {
public:
    virtual ~Character() = default;

    virtual void display() const = 0;
};

// 具体享元类
class ConcreteCharacter final : public Character {
    char symbol;

public:
    explicit ConcreteCharacter(const char s) : symbol(s) {}

    void display() const override {
        std::cout << symbol << " ";
    }
};

// 享元工厂
class CharacterFactory {
    std::unordered_map<char, std::shared_ptr<Character>> characters;

public:
    std::shared_ptr<Character> getCharacter(char symbol) {
        if (!characters.contains(symbol)) {
            characters[symbol] = std::make_shared<ConcreteCharacter>(symbol);
        }
        return characters[symbol];
    }
};

// 客户端
class Text {
    CharacterFactory factory;
public:
    void addCharacter(const char symbol) {
        const auto character = factory.getCharacter(symbol);
        character->display();
    }
};

int main() {
    Text text;
    text.addCharacter('A');
    text.addCharacter('B');
    text.addCharacter('A');  // 重用 'A'

    std::cout << std::endl;
    return 0;
}
