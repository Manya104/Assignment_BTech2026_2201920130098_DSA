class Solution {
public:
    string convertToTitle(int columnNumber) {
        string result = "";
        while (columnNumber > 0) {
            columnNumber--;  // Adjust to 0-based index for proper mapping
            char ch = 'A' + (columnNumber % 26);  // Get character
            result = ch + result;  // Append character at the front
            columnNumber /= 26;  // Move to the next place
        }
        return result;
    }
};