class Solution {
public:
    bool isPalindrome(string s) {

        int i = 0;
        int j = s.length() - 1;

        while(i < j) {

            // Skip non-alphanumeric characters from left
            if(!isalnum(s[i])) {
                i++;
                continue;
            }

            // Skip non-alphanumeric characters from right
            if(!isalnum(s[j])) {
                j--;
                continue;
            }

            // Convert both characters to lowercase
            char left = tolower(s[i]);
            char right = tolower(s[j]);

            // If characters don't match, not a palindrome
            if(left != right) {
                return false;
            }

            // Move both pointers towards the center
            i++;
            j--;
        }

        // All characters matched
        return true;
    }
};