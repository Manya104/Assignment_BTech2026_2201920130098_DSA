class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size(); // Size of the array
        int even = 1, odd = 0; // Initialize counts of even and odd prefix sums
        int sum = 0, mod = 1e9 + 7; // Running sum and modulo value
        long long int ans = 0; // Result to store the number of subarrays with odd sum

        for (int i = 0; i < n; ++i) {
            sum += arr[i]; // Update the running sum
            if (sum & 1) { // If the sum is odd
                ++odd; // Increment the count of odd prefix sums
                ans = (ans + even) % mod; // Add the number of even prefix sums to the result
            } else { // If the sum is even
                ++even; // Increment the count of even prefix sums
                ans = (ans + odd) % mod; // Add the number of odd prefix sums to the result
            }
        }

        return ans; // Return the final result
    }
};