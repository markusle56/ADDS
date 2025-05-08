#include "MergeSort.h"

void MergeSortHelperMid(std::vector<int> & list, int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    std::vector<int> buffer;
    while (i <= mid || j <= right) {
        if (i > mid) {
            buffer.push_back(list[j]);
            j++;
        } else if (j > right) {
            buffer.push_back(list[i]);
            i++;
        } else if (list[i] >= list[j]) {
            buffer.push_back(list[j]);
            j++;
        } else {
            buffer.push_back(list[i]);
            i++;
        }
    }
    int count = 0;
    for (int i = left; i <= right; i++) {
        list[i] = buffer[count];
        count++;
    }
}

void MergeSortHelper(std::vector<int> & list, int left, int right) {
    if (left >= right) {
        return;
    }
    
    int mid = (right + left) /2;
    MergeSortHelper(list, left, mid); 
    MergeSortHelper(list, mid+1, right);
    MergeSortHelperMid(list, left, mid, right);
}



std::vector<int> MergeSort::sort(std::vector<int> list) {
    MergeSortHelper(list, 0, list.size()-1);
    return list;
}