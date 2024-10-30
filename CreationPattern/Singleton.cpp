// @Time: 2024/10/29 16:29
// @Author: ACHIEVE_DREAM
// @File: Singleton.cpp
// @Software: CLion
#include <iostream>

class Singleton {
public:
    // 禁用拷贝构造函数和赋值运算符
    Singleton(const Singleton &) = delete;

    Singleton &operator=(const Singleton &) = delete;

    // 提供全局访问点
    static Singleton &getInstance() {
        static Singleton instance; // 局部静态变量，确保只初始化一次
        return instance;
    }

    // 示例方法
    void showMessage() {
        std::cout << "单例实例方法调用成功！\n";
    }

private:
    // 私有构造函数，防止外部创建实例
    Singleton() {
        std::cout << "单例实例已创建！\n";
    }
};

int main() {
    Singleton::getInstance().showMessage();
    return 0;
}
