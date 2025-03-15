class Solution {
public:
    int longestValidParentheses(string s) {
        int maxLen = 0;
    stack<int> st;
    
    // Push -1 as a base index to help calculate lengths of valid substrings.
    st.push(-1);
    
    // Process each character by its index.
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            // Push the index of the '(' onto the stack.
            st.push(i);
        } else { // s[i] == ')'
            // Pop the top element which corresponds to a matching '(' (if exists).
            st.pop();
            
            // If the stack becomes empty, push the current index as the new base.
            if (st.empty()) {
                st.push(i);
            } else {
                // The current valid substring length is i - st.top().
                // st.top() now holds the index just before the start of the valid substring.
                maxLen = max(maxLen, i - st.top());
            }
        }
    }
    
    return maxLen;
    }
};