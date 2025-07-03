class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> votes(n + 1, 0); // Keep track of votes
        vector<bool> trustsSomeone(n + 1, false); 

        for (auto& relation : trust) {
            int truster = relation[0];
            int trusted = relation[1];
            votes[trusted]++; // Increment votes
            trustsSomeone[truster] = true; // Mark as trusts someone
        }

        // Iterate through all town people to...
        // ...find who meets the judge conditions
        for (int i = 1; i <= n; i++) 
            if (votes[i] == n - 1 && !trustsSomeone[i]) return i;

        return -1; // No one met judge conditions
    }
};