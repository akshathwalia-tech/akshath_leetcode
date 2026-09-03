/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    // Checks if the list matches a continuous path starting exactly at 'root'
    bool checkPath(ListNode* head, TreeNode* root) {
        // Base case 1: Matched the entire linked list
        if (!head) return true;
        // Base case 2: Ran out of tree nodes before matching the list
        if (!root) return false;
        // Base case 3: Values do not match
        if (head->val != root->val) return false;

        // Continue matching downward (must match consecutively)
        return checkPath(head->next, root->left) || checkPath(head->next, root->right);
    }

public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        if (!root) return false;

        // Either the path starts at the current tree node,
        // or it starts somewhere in the left/right subtree
        return checkPath(head, root) || 
               isSubPath(head, root->left) || 
               isSubPath(head, root->right);
    }
};