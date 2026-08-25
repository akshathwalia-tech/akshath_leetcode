class Solution {
public:
    // Function to perform zigzag (spiral) level order traversal of a binary tree
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        // Vector to store the final zigzag traversal result
        vector<vector<int>> result;
        // If the tree is empty, return an empty result
        if (!root) return result;

        // Queue to store nodes level by level (BFS)
        queue<TreeNode*> q;
        q.push(root);

        // Boolean flag to control traversal direction: true for left-to-right, false for right-to-left
        bool leftToRight = true;

        // Loop until all levels are processed
        while (!q.empty()) {
            // Get the number of nodes at the current level
            int size = q.size();

            // Temporary vector to store the current level's values in correct zigzag order
            vector<int> level(size);

            // Process each node in the current level
            for (int i = 0; i < size; i++) {
                // Get the front node from the queue
                TreeNode* node = q.front();
                q.pop();

                // Determine index where this node's value should be placed based on traversal direction
                int index = leftToRight ? i : size - 1 - i;
                level[index] = node->val;

                // If left child exists, add it to the queue
                if (node->left) q.push(node->left);
                // If right child exists, add it to the queue
                if (node->right) q.push(node->right);
            }

            // After finishing this level, toggle the direction for the next level
            leftToRight = !leftToRight;

            // Add this level's data to the final result
            result.push_back(level);
        }

        // Return the zigzag traversal result
        return result;
    }
};