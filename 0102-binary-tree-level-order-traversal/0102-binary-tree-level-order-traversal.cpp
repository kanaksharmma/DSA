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
    vector<vector<int>> levelOrder(TreeNode* root) {

        // Final answer containing all levels
        vector<vector<int>> ans;

        // If tree is empty, return empty answer
        if (root == NULL)
            return ans;

        // Queue is used for BFS (Level Order Traversal)
        queue<TreeNode*> q;

        // Start by inserting the root node
        q.push(root);

        // Continue until all nodes are visited
        while (!q.empty()) {

            // Number of nodes present in the current level
            int size = q.size();

            // Stores all nodes of the current level
            vector<int> level;

            // Process exactly 'size' nodes
            for (int i = 0; i < size; i++) {

                // Take the front node
                TreeNode* node = q.front();
                q.pop();

                // Store its value
                level.push_back(node->val);

                // Add left child for next level
                if (node->left != NULL)
                    q.push(node->left);

                // Add right child for next level
                if (node->right != NULL)
                    q.push(node->right);
            }

            // Current level is completed
            ans.push_back(level);
        }

        return ans;
    }
};