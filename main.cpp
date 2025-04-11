#include <iostream>
#include <vector>
#include "QuickSort.h"
#include "RecursiveBinarySearch.h"

int main() {
    std::vector<int> nums = {1, 3, 5, 4, -5, 100, 7777, 2014};
    QuickSort qs;
    std::vector<int> sortedList = qs.sort(nums);
    RecursiveBinarySearch rbs;
    bool found = rbs.search(sortedList, 1);
    std::cout << (found ? "true" : "false");
    for (int num : sortedList) {
        std::cout << " " << num;
    }
    std::cout << std::endl;

    return 0;
}