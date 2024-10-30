// @Time: 2024/10/29 15:58
// @Author: ACHIEVE_DREAM
// @File: Prototype.cpp
// @Software: CLion
#include <iostream>
#include <memory>

// 抽象原型类
class Shape {
public:
    virtual ~Shape() = default;

    [[nodiscard]] virtual std::unique_ptr<Shape> clone() const = 0; // 克隆方法
    virtual void draw() const = 0; // 绘制方法
};

// 具体原型类1：矩形
class Rectangle final : public Shape {
    int width, height;

public:
    Rectangle(const int w, const int h) : width(w), height(h) {
    }

    [[nodiscard]] std::unique_ptr<Shape> clone() const override {
        return std::make_unique<Rectangle>(*this); // 通过复制构造函数克隆
    }

    void draw() const override {
        std::cout << "绘制矩形，宽度：" << width << "，高度：" << height << '\n';
    }
};

// 具体原型类2：圆形
class Circle final : public Shape {
    int radius;

public:
    explicit Circle(const int r) : radius(r) {
    }

    [[nodiscard]] std::unique_ptr<Shape> clone() const override {
        return std::make_unique<Circle>(*this); // 通过复制构造函数克隆
    }

    void draw() const override {
        std::cout << "绘制圆形，半径：" << radius << '\n';
    }
};

// 客户端代码
void duplicateAndDraw(const Shape &shape) {
    const auto newShape = shape.clone();
    newShape->draw();
}

int main() {
    const Rectangle rect(10, 20);
    const Circle circle(15);
    std::cout << "原始图形：\n";
    rect.draw();
    circle.draw();
    std::cout << "\n克隆图形：\n";
    duplicateAndDraw(rect);
    duplicateAndDraw(circle);

    return 0;
}
