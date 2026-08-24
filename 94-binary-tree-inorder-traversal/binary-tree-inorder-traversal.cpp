class Solution {
private:
    void inorder(TreeNode* node, vector<int>& ans) {
        if (!node) return;
        inorder(node->left, ans);   // Left
        ans.push_back(node->val);  // Root
        inorder(node->right, ans);  // Right
    }

public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        inorder(root, ans);
        return ans;
    }
};