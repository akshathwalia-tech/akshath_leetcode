class Solution {
public:
    void solve(Node* root, vector<int>& ans) {
        if (root == nullptr) {
            return;
        }

        // Visit root first
        ans.push_back(root->val);

        // Then visit all children
        for (Node* child : root->children) {
            solve(child, ans);
        }
    }

    vector<int> preorder(Node* root) {
        vector<int> ans;

        solve(root, ans);

        return ans;
    }
};