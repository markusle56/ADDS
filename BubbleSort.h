#ifndef BUBBLE_SORT
#define BUBBLE_SORT
#include "Sort.h"

class BubbleSort : Sort { 
    public: 
    std::vector<int> sort(std::vector<int> list) override;
};
#endif