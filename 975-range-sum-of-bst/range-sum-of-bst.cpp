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
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (!root) {
            return 0;
        }

        // Case 1: Current node is smaller than low.
        // Everything in the left subtree is also smaller, so only search right.
        if (root->val < low) {
            return rangeSumBST(root->right, low, high);
        }

        // Case 2: Current node is greater than high.
        // Everything in the right subtree is also greater, so only search left.
        if (root->val > high) {
            return rangeSumBST(root->left, low, high);
        }

        // Case 3: Current node is within [low, high].
        // Include its value and search both subtrees.
        return root->val + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
    }
};