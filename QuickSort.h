#ifndef QUICK_SORT
#define QUICK_SORT 
#include "Sort.h" 

class QuickSort : Sort {
    public: 
    std::vector<int> sort(std::vector<int> list) override;
};
#endif 