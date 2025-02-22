/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* recoverFromPreorder(string traversal) {
        stack<pair<TreeNode*, int>> st;
        int i = 0, n = traversal.length();
        
        // Extract root node
        int num = 0;
        while (i < n && isdigit(traversal[i])) {
            num = num * 10 + (traversal[i] - '0');
            i++;
        }
        TreeNode* root = new TreeNode(num);
        st.push({root, 0});
        
        while (i < n) {
            int depth = 0;
            
            // Count depth (number of '-')
            while (i < n && traversal[i] == '-') {
                depth++;
                i++;
            }
            
            // Extract the number (multi-digit handling)
            num = 0;
            while (i < n && isdigit(traversal[i])) {
                num = num * 10 + (traversal[i] - '0');
                i++;
            }
            
            // Create new node
            TreeNode* newnode = new TreeNode(num);
            
            // Find correct parent node
            while (!st.empty() && st.top().second >= depth) {
                st.pop();
            }
            
            // Attach to the parent
            TreeNode* parent = st.top().first;
            if (!parent->left) parent->left = newnode;
            else parent->right = newnode;
            
            // Push new node with its depth
            st.push({newnode, depth});
        }
        
        return root;
    }
};