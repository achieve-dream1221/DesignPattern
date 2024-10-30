// @Time: 2024/10/30 16:55
// @Author: ACHIEVE_DREAM
// @File: Iterator.cpp
// @Software: CLion
#include <iostream>
#include <vector>
#include <memory>

// 迭代器接口
template <typename T>
class Iterator {
public:
    virtual ~Iterator() = default;
    [[nodiscard]] virtual bool hasNext() const = 0;
    virtual T next() = 0;
};

// 集合接口
template <typename T>
class Iterable {
public:
    virtual ~Iterable() = default;
    virtual std::shared_ptr<Iterator<T>> createIterator() = 0;
};

// 具体集合
class ConcreteCollection final : public Iterable<int> {

    std::vector<int> items;

public:
    void add(const int item) {
        items.emplace_back(item);
    }

    class ConcreteIterator final : public Iterator<int> {
        ConcreteCollection& collection;
        size_t index;

    public:
        explicit ConcreteIterator(ConcreteCollection& c) : collection(c), index(0) {}

        [[nodiscard]] bool hasNext() const override {
            return index < collection.items.size();
        }

        int next() override {
            return collection.items[index++];
        }
    };

    std::shared_ptr<Iterator<int>> createIterator() override {
        return std::make_shared<ConcreteIterator>(*this);
    }
};

// 客户端
int main() {
    ConcreteCollection collection;
    collection.add(1);
    collection.add(2);
    collection.add(3);

    const auto iterator = collection.createIterator();

    while (iterator->hasNext()) {
        std::cout << iterator->next() << " ";
    }
    std::cout << std::endl;

    return 0;
}
