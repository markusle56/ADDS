#ifndef MERGE_SORT
#define MERGE_SORT
#include "Sort.h"
class MergeSort : Sort {
    public: 
    std::vector<int> sort(std::vector<int> list) override;
};
#endif