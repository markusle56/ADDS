#include "BubbleSort.h" 


std::vector<int> BubbleSort::sort(std::vector<int> list) {
    int n = list.size();
    for (int i = 0; i < n-1; i++) {
        for (int j = i; j < n-i-1; j++) {
            if (list[j] > list[j+1]) {
                int buffer = list[j];
                list[j] = list[j+1]; 
                list[j+1] = buffer; 
            }
        }
    }
    return list;
}