class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        if (n == 0 || s[0] == '0') return 0;

        int prev2 = 1;                         // dp[0]
        int prev1 = 1;                         // dp[1]

        for (int i = 1; i < n; i++) {
            int curr = 0;

            // Check single digit (s[i])
            if (s[i] != '0')
                curr += prev1;

            // Check two digits (s[i-1]s[i])
            int twoDigit = stoi(s.substr(i - 1, 2));
            if (twoDigit >= 10 && twoDigit <= 26)
                curr += prev2;

            // Move forward
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};