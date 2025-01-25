#include <queue>
#include <vector>
#include <iostream>

using namespace std;

class KthLargest {
public:
    int K;  // To store the value of k
    priority_queue<int, vector<int>, greater<int>> pq;  // Min-heap to store the k largest elements

    KthLargest(int k, vector<int>& nums) {
        K = k;  // Initialize k
        for (int num : nums) {
            if (pq.size() < K) {
                pq.push(num);  // Push element into the heap if size is less than k
            } else if (num > pq.top()) {
                pq.pop();      // Remove the smallest element
                pq.push(num);  // Add the current element
            }
        }
    }

    int add(int val) {
        if (pq.size() < K) {
            pq.push(val);  // Push element if size is less than k
        } else if (val > pq.top()) {
            pq.pop();      // Remove the smallest element
            pq.push(val);  // Add the new value
        }
        return pq.top();  // The top of the heap is the kth largest element
    }
};
/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */