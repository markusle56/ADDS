#include "BigNumCalc.h"
#include <iostream>
#include <cassert>

void testAddition() {
    // Example: Assuming addBigNumbers is a function in bigNumCalc.h
    std::string num1 = "123456789123456789";
    std::string num2 = "987654321987654321";
    std::list<int> n1 = buildBigNum(num1);
    std::list<int> n2 = buildBigNum(num2);
    std::string result = add(n1, n2);
    assert(result == buildBugNum("1111111111111111110"));
    std::cout << "testAddition passed!" << std::endl;
}

void testSubtraction() {
    // Example: Assuming subtractBigNumbers is a function in bigNumCalc.h
    std::string num1 = "987654321987654321";
    std::string num2 = "123456789123456789";
    std::string result = sub(num1, num2);
    assert(result == "864197532864197532");
    std::cout << "testSubtraction passed!" << std::endl;
}

void testMultiplication() {
    // Example: Assuming multiplyBigNumbers is a function in bigNumCalc.h
    std::string num1 = "123456789";
    std::string num2 = "987654321";
    std::string result = mul(num1, num2);
    assert(result == "121932631112635269");
    std::cout << "testMultiplication passed!" << std::endl;
}

void testDivision() {
    // Example: Assuming divideBigNumbers is a function in bigNumCalc.h
    std::string num1 = "121932631112635269";
    std::string num2 = "123456789";
    std::string result = divideBigNumbers(num1, num2);
    assert(result == "987654321");
    std::cout << "testDivision passed!" << std::endl;
}

int main() {
    testAddition();
    testSubtraction();
    testMultiplication();
    testDivision();
    std::cout << "All tests passed!" << std::endl;
    return 0;
}