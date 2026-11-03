class Solution {
public:
    string reverseWords(string s) {
         string ans = "";
    string word = "";

    for (int i = 0; i <= s.length(); i++) {

        // If space or end of string is reached
        if (i == s.length() || s[i] == ' ') {

            // Reverse the current word
            reverse(word.begin(), word.end());

            // Add reversed word to answer
            ans += word;

            // Add space if it is not the last word
            if (i != s.length()) {
                ans += ' ';
            }

            // Clear word for next iteration
            word = "";
        }
        else {
            // Build the current word
            word += s[i];
        }
    }

    return ans;
    }
};