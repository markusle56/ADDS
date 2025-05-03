// BigNumCalc_test.cpp
#include <iostream>
#include <string>
#include <list>
#include <cassert>
#include "BigNumCalc.h"

// Helper: convert list<int> to string (preserves all digits)
std::string listToString(const std::list<int>& num) {
    if (num.empty()) return "0";
    std::string s;
    for (int d : num) {
        s.push_back(char('0' + d));
    }
    return s;
}

void testBuild() {
    BigNumCalc calc;
    std::string in = "0012345";
    auto out = calc.buildBigNum(in);
    std::string s = listToString(out);
    std::cout << "buildBigNum(\"" << in << "\") = \"" << s << "\"  (expected \"0012345\")\n";
    assert(s == "0012345");
}

void testAddBasic() {
    BigNumCalc calc;
    auto a = calc.buildBigNum("999");
    auto b = calc.buildBigNum("1");
    auto sum = calc.add(a, b);
    std::string s = listToString(sum);
    std::cout << "add(999,1) = " << s << "  (expected 1000)\n";
    assert(s == "1000");
}

void testSub() {
    BigNumCalc calc;
    auto a = calc.buildBigNum("1000");
    auto b = calc.buildBigNum("1");
    auto diff = calc.sub(a, b);
    std::string s = listToString(diff);
    std::cout << "sub(1000,1) = " << s << "  (expected 999)\n";
    assert(s == "999");
}

void testMul() {
    BigNumCalc calc;
    auto a = calc.buildBigNum("12345");
    auto b = calc.buildBigNum("6");    // single-digit
    auto prod = calc.mul(a, b);
    std::string s = listToString(prod);
    std::cout << "mul(12345,6) = " << s << "  (expected 74070)\n";
    assert(s == "74070");
}

void testEdgeCases() {
    BigNumCalc calc;
    auto z = calc.buildBigNum("0");
    assert(listToString(calc.add(z, z)) == "0");
    assert(listToString(calc.sub(z, z)) == "0");
    assert(listToString(calc.mul(z, z)) == "0");
}

// ** New: test the specific failing case **
void testLargeAdd() {
    BigNumCalc calc;
    auto n1 = calc.buildBigNum("1234567890");
    auto n2 = calc.buildBigNum("9876543210");
    auto sum = calc.add(n1, n2);
    std::string s = listToString(sum);
    std::cout << "add(1234567890,9876543210) = " << s 
              << "  (expected 11111111100)\n";
    assert(s == "11111111100");
}

int main() {
    try {
        testBuild();
        testAddBasic();
        testSub();
        testMul();
        testEdgeCases();
        testLargeAdd();             // invoke our new test
        std::cout << "\nAll tests passed!\n";
        return 0;
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << "\n";
        return 1;
    }
    catch (...) {
        std::cerr << "A test assertion failed.\n";
        return 1;
    }
}
