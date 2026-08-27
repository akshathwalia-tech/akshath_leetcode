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
private:
    struct SubtreeInfo {
        bool isBST;
        int minVal;
        int maxVal;
        int sum;
    };

    int maxSum = 0;

    SubtreeInfo postOrder(TreeNode* root) {
        // Base case: an empty tree is a valid BST
        if (!root) {
            return {true, INT_MAX, INT_MIN, 0};
        }

        SubtreeInfo left = postOrder(root->left);
        SubtreeInfo right = postOrder(root->right);

        // Check if the current tree forms a valid BST
        if (left.isBST && right.isBST && left.maxVal < root->val && root->val < right.minVal) {
            int currentSum = left.sum + right.sum + root->val;
            maxSum = std::max(maxSum, currentSum);

            int minVal = (root->left) ? left.minVal : root->val;
            int maxVal = (root->right) ? right.maxVal : root->val;

            return {true, minVal, maxVal, currentSum};
        }

        // Not a valid BST; return values that will invalidate any parent
        return {false, 0, 0, 0};
    }

public:
    int maxSumBST(TreeNode* root) {
        maxSum = 0;
        postOrder(root);
        return maxSum;
    }
};