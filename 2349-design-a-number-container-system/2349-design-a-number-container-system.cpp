class NumberContainers {
public:
    map<int, set<int>> mpp; // Number -> Sorted indices
    map<int, int> mp;       // Index -> Number

    NumberContainers() {}

    void change(int index, int number) {
        if (mp[index]) {
            int val = mp[index];
            mpp[val].erase(index); // Remove index from old number's set
            mp[index] = number;    // Update index to new number
        } else {
            mp[index] = number;    // Insert new index-number pair
        }
        mpp[number].insert(index); // Add index to new number's set
    }

    int find(int number) {
        if (mpp[number].empty()) return -1; // No indices for the number
        return *(mpp[number].begin());      // Smallest index
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */