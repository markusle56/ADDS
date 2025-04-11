#include "RecursiveBinarySearch.h" 

bool RecursiveBinarySearch::search(std::vector<int> list, int n) {
    if (list.empty()) {
        return false;
    }
    int middle = list.size() / 2;
    if (list[middle] == n) {
        return true;
    } else if (list[middle] > n) {
        std::vector<int> leftSublist(list.begin(), list.begin() + middle);
        return search(leftSublist, n);
    } else {
        std::vector<int> rightSublist(list.begin() + middle + 1 , list.end());
        return search(rightSublist, n);
    }
}