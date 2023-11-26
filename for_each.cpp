#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <cctype>

std::vector<int> v{18,4,6,8,26,2,-10,2,0,-32};
std::map<int, std::string> m{{1, "Hello"}, {2, "World"}, {3, "12a23"}, {4, "[]]67dx"}};

void PrintVec(const auto& v) {
    for(const auto& val : v) {
        std::cout<<val<<" ";
    } std::cout<<"\n";
}

void PrintMap(const auto& v) {
    for(const auto& val : v) {
        std::cout<<val.second<<" ";
    } std::cout<<"\n";
}

void test_for_each() {
    // vector
    auto multiplyBy4 = [](const auto& elem) { return elem * 4; };
    std::cout<<"Before multiplying all values by 4: \n";
    PrintVec(v);
    std::for_each(std::begin(v), std::end(v), multiplyBy4);
    std::cout<<"After multiplying all values by 4: \n";
    PrintVec(v);
    std::cout<<"\n\n";
    
    // map
    auto letterToUnderscore = [](auto& elem) { 
        std::for_each(std::begin(elem.second), std::end(elem.second), [](auto& c) { if(std::isalpha(c)) { c = '_'; } });
    };
    std::cout<<"Before converting all letters into underscore: \n";
    PrintMap(m);
    std::for_each(std::begin(m), std::end(m), letterToUnderscore);
    std::cout<<"After converting all letters into underscore: \n";
    PrintMap(m);
}

int main() {
    test_for_each();
    return 0;
}