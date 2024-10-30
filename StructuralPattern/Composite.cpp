// @Time: 2024/10/29 16:59
// @Author: ACHIEVE_DREAM
// @File: Composite.cpp
// @Software: CLion
#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>

// 抽象基类，表示组件
class Component {
public:
    virtual void operation() const = 0; // 定义统一的接口
    virtual void add(const std::shared_ptr<Component> &component) {
    }

    virtual void remove(const std::shared_ptr<Component> &component) {
    }

    [[nodiscard]] virtual std::shared_ptr<Component> getChild(int index) const { return nullptr; }

    virtual ~Component() = default;
};

// 叶子节点类，表示树的叶子节点
class Leaf final : public Component {
public:
    void operation() const override {
        std::cout << "Leaf: 进行叶子节点操作" << std::endl;
    }
};

// 组合节点类，表示可以包含子节点的复杂节点
class Composite final : public Component {
    std::vector<std::shared_ptr<Component> > children;

public:
    void operation() const override {
        std::cout << "Composite: 组合节点操作，通知子节点：" << std::endl;
        for (const auto &child: children) {
            child->operation();
        }
    }

    void add(const std::shared_ptr<Component> &component) override {
        children.push_back(component);
    }

    void remove(const std::shared_ptr<Component> &component) override {
        children.erase(std::ranges::remove(children, component).begin(), children.end());
    }

    [[nodiscard]] std::shared_ptr<Component> getChild(const int index) const override {
        if (index >= 0 && index < children.size()) {
            return children[index];
        }
        return nullptr;
    }
};

int main() {
    // 创建叶子节点
    const auto leaf1 = std::make_shared<Leaf>();
    const auto leaf2 = std::make_shared<Leaf>();

    // 创建组合节点
    const auto composite1 = std::make_shared<Composite>();
    const auto composite2 = std::make_shared<Composite>();

    // 构建树形结构
    composite1->add(leaf1); // 添加叶子节点
    composite1->add(composite2); // 添加组合节点
    composite2->add(leaf2); // 添加叶子节点

    // 调用操作
    std::cout << "执行组合结构操作：" << std::endl;
    composite1->operation();

    return 0;
}
