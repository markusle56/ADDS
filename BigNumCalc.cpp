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
    for (it1; it1 != num1.rend() || it2 != num2.rend() || carry; ++it1, ++it2) {
        int sum = carry;
        if (it1 != num1.rend()) {
            sum += *it1;
        }
        if (it2 != num2.rend()) {
            sum += *it2;
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
    for (it1; it1 != num1.rend() || it2 != num2.rend(); ++it1, ++it2) {
        int diff = borrow; 
        if (it1 != num1.rend()) {
            diff += *it1;
        } 
        if (it2 != num2.rend()) {
            diff -= *it2;
        }
        if (diff < 0) { 
            diff += 10; 
            borrow = -1;
        } else { 
            borrow = 0;
        }
        result.push_front(diff);

    }
    
}
std::list<int> BigNumCalc::mul(std::list<int> num1, std::list<int> num2) {
    std::list<int> result;
    auto it1 = num1.rbegin();
    auto it2 = num2.rbegin();
    int carry = 0;
    for (it1; it1 != num1.rend(); ++it1) {
        std::list<int> tempResult;
        carry = 0;
        for (it2 = num2.rbegin(); it2 != num2.rend(); ++it2) {
            int prod = (*it1) * (*it2) + carry;
            tempResult.push_front(prod % 10);
            carry = prod / 10;
        }
        if (carry) {
            tempResult.push_front(carry);
        }
        result.insert(result.end(), tempResult.begin(), tempResult.end());
    }
    return result;
}