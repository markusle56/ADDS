#include <vector>
#include <queue>

int kth_largest(std::vector<int> values, int k) {
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

    for (int val : values) {
        minHeap.push(val);
        if (minHeap.size() > k) {
            minHeap.pop();
        }
    }
    return minHeap.top();
}