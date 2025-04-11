#include "QuickSort.h"

void swap(std::vector<int>& list, int a, int b) {
    int buffer = list[a];
    list[a] = list[b];
    list[b] = buffer;
}

int partition(std::vector<int>& list, int low, int high) {
    int pointer = low - 1; 
    for (int i = low; i < high; i++) {
        if(list[i] < list[high]) {
            pointer++;
            swap(list, pointer, i);
        }
    }
    swap(list, pointer + 1, high);
    return pointer+1;
}
void quickSortHelper(std::vector<int>& list, int low, int high) {
    if (low >= high) {
        return; 
    }
    int pivot = partition(list, low, high);

    quickSortHelper(list, low, pivot - 1);
    quickSortHelper(list, pivot + 1, high);
}
std::vector<int> QuickSort::sort(std::vector<int> list) {
    if(list.empty()) {
        return list;
    }
    quickSortHelper(list, 0, list.size()-1);
    return list;
}