// @Time: 2024/10/30 16:23
// @Author: ACHIEVE_DREAM
// @File: Filter.cpp
// @Software: CLion
#include <iostream>
#include <vector>
#include <string>
#include <memory>

// 过滤器接口
class Filter {
public:
    virtual ~Filter() = default;
    [[nodiscard]] virtual std::vector<std::string> apply(const std::vector<std::string>& items) const = 0;
};

// 具体过滤器：长度过滤器
class LengthFilter final : public Filter {
    size_t lengthThreshold;
public:
    explicit LengthFilter(const size_t length) : lengthThreshold(length) {}

    [[nodiscard]] std::vector<std::string> apply(const std::vector<std::string>& items) const override {
        std::vector<std::string> result;
        for (const auto& item : items) {
            if (item.size() >= lengthThreshold) {
                result.emplace_back(item);
            }
        }
        return result;
    }
};

// 具体过滤器：字母过滤器
class LetterFilter final : public Filter {
    char letter;
public:
    explicit LetterFilter(const char l) : letter(l) {}

    [[nodiscard]] std::vector<std::string> apply(const std::vector<std::string>& items) const override {
        std::vector<std::string> result;
        for (const auto& item : items) {
            if (item.contains(letter)) {
                result.emplace_back(item);
            }
        }
        return result;
    }
};

// 过滤器组合
class FilterChain {
    std::vector<std::shared_ptr<Filter>> filters;
public:
    void addFilter(const std::shared_ptr<Filter>& filter) {
        filters.push_back(filter);
    }

    [[nodiscard]] std::vector<std::string> apply(const std::vector<std::string>& items) const {
        std::vector<std::string> result = items;
        for (const auto& filter : filters) {
            result = filter->apply(result);
        }
        return result;
    }
};

int main() {
    const std::vector<std::string> items = {"apple", "banana", "grape", "kiwi", "orange"};

    FilterChain filterChain;
    filterChain.addFilter(std::make_shared<LengthFilter>(5));
    filterChain.addFilter(std::make_shared<LetterFilter>('a'));

    for (const auto filteredItems = filterChain.apply(items); const auto& item : filteredItems) {
        std::cout << item << std::endl;
    }

    return 0;
}
