// @Time: 2024/10/29 14:51
// @Author: ACHIEVE_DREAM
// @File: Builder.cpp
// @Software: CLion
#include <iostream>
#include <string>

class Computer {
public:
    std::string cpu;
    std::string gpu;
    int ram{};
    int storage{};

    void showConfig() const {
        std::cout << "CPU: " << cpu << "\n"
                  << "GPU: " << gpu << "\n"
                  << "RAM: " << ram << "GB\n"
                  << "Storage: " << storage << "GB\n";
    }
};

class ComputerBuilder {
    Computer computer;
public:
    ComputerBuilder& setCPU(const std::string& cpu) {
        computer.cpu = cpu;
        return *this;
    }

    ComputerBuilder& setGPU(const std::string& gpu) {
        computer.gpu = gpu;
        return *this;
    }

    ComputerBuilder& setRAM(int ram) {
        computer.ram = ram;
        return *this;
    }

    ComputerBuilder& setStorage(int storage) {
        computer.storage = storage;
        return *this;
    }

    [[nodiscard]] Computer build() const {
        return computer;
    }
};

int main() {
    const Computer myComputer = ComputerBuilder()
        .setCPU("Intel i7")
        .setGPU("NVIDIA GTX 3060")
        .setRAM(16)
        .setStorage(512)
        .build();

    myComputer.showConfig();
    return 0;
}
