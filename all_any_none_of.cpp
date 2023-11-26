#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <cctype>

std::vector<int> v{18,4,6,8,26,2,-10,2,0,-32};
std::map<int, std::string> m{{1, "Hello"}, {2, "World"}, {3, "12a23"}, {4, "[]]67dx"}};

auto isEven = [](const auto& elem) {
    return (elem % 2 == 0);
};

auto isAlpha = [](const auto& elem) {
    return std::any_of(std::begin(elem.second), std::end(elem.second), [](const auto& c) { return std::isalpha(c);});
};

void test_all_of() {
    // vector
    auto areAllEven = std::all_of(std::begin(v), std::end(v), isEven);
    std::cout<<"Are all numbers in the vector even? -> "<<areAllEven<<"\n";

    // map
    auto doAllHaveChar = std::all_of(std::begin(m), std::end(m), isAlpha);
    std::cout<<"Do all values in map have a letter? -> "<<doAllHaveChar<<"\n";
}

void test_any_of() {
    // vector
    auto isAnyEven = std::any_of(std::begin(v), std::end(v), isEven);
    std::cout<<"Is any number in the vector even? -> "<<isAnyEven<<"\n";

    // map
    auto doesAnyHaveChar = std::any_of(std::begin(m), std::end(m), isAlpha);
    std::cout<<"Does any value in map have a letter? -> "<<doesAnyHaveChar<<"\n";
}

void test_none_of() {
    // vector
    auto areNoneOdd = std::none_of(std::begin(v), std::end(v), isEven);
    std::cout<<"Are none of the numbers in vector even? -> "<<areNoneOdd<<"\n";

    // map
    auto areNoneAlpha = std::none_of(std::begin(m), std::end(m), isAlpha);
    std::cout<<"Are none of the values in map letters? -> "<<areNoneAlpha<<"\n";
}

int main() {
    test_all_of();
    test_any_of();
    test_none_of();
    return 0;
}