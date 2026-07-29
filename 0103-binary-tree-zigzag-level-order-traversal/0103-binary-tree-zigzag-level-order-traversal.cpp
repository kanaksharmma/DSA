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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        // This will store the final answer
        vector<vector<int>> result;

        // If the tree is empty, return an empty result
        if (root == NULL) {
            return result;
        }

        // Queue is used for Level Order Traversal (BFS)
        queue<TreeNode*> nodesQueue;
        nodesQueue.push(root);

        // This flag tells us the direction of each level
        // true  -> Left to Right
        // false -> Right to Left
        bool LeftToRight = true;

        // Continue until all nodes are processed
        while (!nodesQueue.empty()) {

            // Number of nodes present in the current level
            int size = nodesQueue.size();

            // Create a vector of the current level's size
            // We pre-allocate because in zigzag order
            // we may insert values at different indices.
            vector<int> row(size);

            // Process every node of the current level
            for (int i = 0; i < size; i++) {

                // Get the front node from the queue
                TreeNode* node = nodesQueue.front();
                nodesQueue.pop();

                // Decide the correct index for insertion
                // LeftToRight = true  -> 0,1,2,...
                // LeftToRight = false -> size-1,size-2,...
                int index = (LeftToRight) ? i : (size - 1 - i);

                // Store the node value at the calculated position
                row[index] = node->val;

                // Add the left child to the queue if it exists
                if (node->left) {
                    nodesQueue.push(node->left);
                }

                // Add the right child to the queue if it exists
                if (node->right) {
                    nodesQueue.push(node->right);
                }
            }

            // Reverse the traversal direction for the next level
            LeftToRight = !LeftToRight;

            // Store the completed level in the result
            result.push_back(row);
        }

        // Return the final zigzag traversal
        return result;
    }
};