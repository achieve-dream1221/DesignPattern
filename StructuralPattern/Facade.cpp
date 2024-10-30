// @Time: 2024/10/30 16:28
// @Author: ACHIEVE_DREAM
// @File: Facade.cpp
// @Software: CLion
#include <iostream>

// 子系统类
class CPU {
public:
    static void freeze() {
        std::cout << "CPU freezing..." << std::endl;
    }
    static void jump() {
        std::cout << "CPU jumping to the start..." << std::endl;
    }
    static void execute() {
        std::cout << "CPU executing..." << std::endl;
    }
};

class Memory {
public:
    static void load() {
        std::cout << "Memory loading..." << std::endl;
    }
};

class HardDrive {
public:
    static void read() {
        std::cout << "Hard drive reading..." << std::endl;
    }
};

// 外观类
class Computer {
    CPU cpu;
    Memory memory;
    HardDrive hardDrive;

public:
    static void start() {
        CPU::freeze();
        Memory::load();
        HardDrive::read();
        CPU::jump();
        CPU::execute();
    }
};

int main() {
    Computer::start();
    return 0;
}
