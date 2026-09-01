/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}
    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return nullptr;

        // leftmost tracks the start of each level
        Node* leftmost = root;

        // Since it's a perfect binary tree, if leftmost->left is null, we've reached the leaves
        while (leftmost->left != nullptr) {
            Node* curr = leftmost;

            // Traverse the current level horizontally using next pointers
            while (curr != nullptr) {
                // Connection 1: Left child -> Right child
                curr->left->next = curr->right;

                // Connection 2: Right child -> Next parent's Left child
                if (curr->next != nullptr) {
                    curr->right->next = curr->next->left;
                }

                // Move horizontally along the current level
                curr = curr->next;
            }

            // Move down to the next level
            leftmost = leftmost->left;
        }

        return root;
    }
};