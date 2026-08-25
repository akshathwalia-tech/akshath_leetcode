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
    int dfs(TreeNode* root, int &maxSum){
          if (!root) return 0;

        // Recursively find left and right max path sums
        int left = max(0, dfs(root->left, maxSum));
        int right = max(0, dfs(root->right, maxSum));

        // Update global max sum considering node as turning point
        maxSum = max(maxSum, left + right + root->val);

        // Return the best one-sided path sum
        return max(left, right) + root->val;
    }
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        dfs(root, maxSum);
        return maxSum; 
    }
};