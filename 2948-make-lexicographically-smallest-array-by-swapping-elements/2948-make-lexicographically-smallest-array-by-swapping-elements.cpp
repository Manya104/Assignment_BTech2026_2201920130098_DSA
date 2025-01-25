class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> result(nums);
        
        // Step 1: Group elements based on the limit
        vector<pair<int, int>> indexed_nums;
        for (int i = 0; i < n; i++) {
            indexed_nums.push_back({nums[i], i});
        }

        sort(indexed_nums.begin(), indexed_nums.end());

        // Step 2: Identify connected components
        vector<bool> visited(n, false);
        for (int i = 0; i < n; i++) {
            if (visited[i]) continue;
            
            vector<int> values, indices;
            int j = i;
            
            while (j < n && (values.empty() || indexed_nums[j].first - values.back() <= limit)) {
                visited[j] = true;
                values.push_back(indexed_nums[j].first);
                indices.push_back(indexed_nums[j].second);
                j++;
            }
            
            sort(values.begin(), values.end());
            sort(indices.begin(), indices.end());

            for (int k = 0; k < values.size(); k++) {
                result[indices[k]] = values[k];
            }
        }
        
        return result;
    }
};