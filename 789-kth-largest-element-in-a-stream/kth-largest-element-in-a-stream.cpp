#include <vector>
#include <queue>

class KthLargest {
private:
    int K;
    // Min-heap to keep the top K largest elements
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

public:
    KthLargest(int k, std::vector<int>& nums) {
        K = k;
        for (int num : nums) {
            add(num);
        }
    }
    
    int add(int val) {
        minHeap.push(val);
        
        // Keep heap size at most K
        if (minHeap.size() > K) {
            minHeap.pop();
        }
        
        return minHeap.top();
    }
};
/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */