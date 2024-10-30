// @Time: 2024/10/29 14:46
// @Author: ACHIEVE_DREAM
// @File: AbstractFactory.cpp
// @Software: CLion
#include <iostream>
#include <memory>

// 抽象产品A（Button按钮接口）
class Button {
public:
    virtual void paint() const = 0;

    virtual ~Button() = default;
};

// 抽象产品B（Checkbox复选框接口）
class Checkbox {
public:
    virtual void paint() const = 0;

    virtual ~Checkbox() = default;
};

// 具体产品A1（Windows风格按钮）
class WindowsButton final : public Button {
public:
    void paint() const override {
        std::cout << "绘制Windows风格按钮\n";
    }
};

// 具体产品B1（Windows风格复选框）
class WindowsCheckbox final : public Checkbox {
public:
    void paint() const override {
        std::cout << "绘制Windows风格复选框\n";
    }
};

// 具体产品A2（MacOS风格按钮）
class MacOSButton final : public Button {
public:
    void paint() const override {
        std::cout << "绘制MacOS风格按钮\n";
    }
};

// 具体产品B2（MacOS风格复选框）
class MacOSCheckbox final : public Checkbox {
public:
    void paint() const override {
        std::cout << "绘制MacOS风格复选框\n";
    }
};

// 抽象工厂（包含创建Button和Checkbox的方法）
class GUIFactory {
public:
    [[nodiscard]] virtual std::unique_ptr<Button> createButton() const = 0;

    [[nodiscard]] virtual std::unique_ptr<Checkbox> createCheckbox() const = 0;

    virtual ~GUIFactory() = default;
};

// 具体工厂1（Windows风格工厂）
class WindowsFactory final : public GUIFactory {
public:
    [[nodiscard]] std::unique_ptr<Button> createButton() const override {
        return std::make_unique<WindowsButton>();
    }

    [[nodiscard]] std::unique_ptr<Checkbox> createCheckbox() const override {
        return std::make_unique<WindowsCheckbox>();
    }
};

// 具体工厂2（MacOS风格工厂）
class MacOSFactory final : public GUIFactory {
public:
    [[nodiscard]] std::unique_ptr<Button> createButton() const override {
        return std::make_unique<MacOSButton>();
    }

    [[nodiscard]] std::unique_ptr<Checkbox> createCheckbox() const override {
        return std::make_unique<MacOSCheckbox>();
    }
};

// 客户端代码
void renderUI(const GUIFactory &factory) {
    const auto button = factory.createButton();
    const auto checkbox = factory.createCheckbox();
    button->paint();
    checkbox->paint();
}

int main() {
    const std::unique_ptr<GUIFactory> windowsFactory = std::make_unique<WindowsFactory>();
    const std::unique_ptr<GUIFactory> macFactory = std::make_unique<MacOSFactory>();
    std::cout << "使用Windows风格组件:\n";
    renderUI(*windowsFactory);
    std::cout << "\n使用MacOS风格组件:\n";
    renderUI(*macFactory);
    return 0;
}
