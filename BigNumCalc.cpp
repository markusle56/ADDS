#include "BigNumCalc.h"

std::list<int> BigNumCalc::buildBigNum(std::string numString) {
    std::list<int> bigNum;
    for (char digit : numString) {
        if (isdigit(digit)) {
            bigNum.push_back(digit - '0');
        }
    }
}
std::list<int> BigNumCalc::add(std::list<int> num1, std::list<int> num2) {
    std::list<int> result; 
    auto it1 = num1.rbegin();
    auto it2 = num2.rbegin();
    int carry = 0; 
    while (it1 != num1.rend() || it2 != num2.rend() || carry) {
        int sum = carry;
        if (it1 != num1.rend()) {
            sum += *it1;
            it1++;
        }
        if (it2 != num2.rend()) {
            sum += *it2;
            it2++;
        }
        result.push_front(sum % 10);
        carry = sum / 10;
    }
    return result;

}
std::list<int> BigNumCalc::sub(std::list<int> num1, std::list<int> num2) {
    std::list<int> result;
    auto it1 = num1.rbegin();
    auto it2 = num2.rbegin();
    int borrow = 0; 
    while (it1 != num1.rend()) {
        int diff = *it1 + borrow;
        it1++;
        if (it2 != num2.rend()) {
            diff -= *it2;
            it2++;
        }
        if (diff < 0) {
            diff += 10;
            borrow = -1;
        } else {
            borrow = 0;
        }
        result.push_front(diff);
        while (result.size() > 1 && result.front() == 0) {
            result.pop_front();
        }
        return result;
    }
    
}
std::list<int> BigNumCalc::mul(std::list<int> num1, std::list<int> num2) {
    std::list<int> result;
    if (num1.empty() || num2.empty()) return result;
    
    int digit = num2.back();
    int carry = 0;
    for (auto it = num1.rbegin(); it != num1.rend(); it++) {
        int prod = (*it) * digit + carry;
        result.push_front(prod % 10);
        carry = prod / 10;
    }
    while (carry) {
        result.push_front(carry % 10);
        carry /= 10;
    }

    while (result.size() > 1 && result.front() == 0) {
        result.pop_front();
    }
    return result;
}