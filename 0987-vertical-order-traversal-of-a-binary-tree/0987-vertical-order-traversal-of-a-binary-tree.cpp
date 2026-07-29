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
    vector<vector<int>> verticalTraversal(TreeNode* root) {

        // Stores:
        // x-coordinate (column)
        //      ↓
        // y-coordinate (row/level)
        //      ↓
        // sorted node values (multiset)
        //
        // Example:
        // nodes[0][2] = {4,5}
        map<int, map<int, multiset<int>>> nodes;

        // Queue stores:
        // (TreeNode*, (x, y))
        //
        // first  -> node
        // second -> (x, y)
        queue<pair<TreeNode*, pair<int, int>>> q;

        // Root starts at column = 0, row = 0
        q.push({root, {0, 0}});

        // Standard BFS
        while (!q.empty()) {

            // Get front element
            auto current = q.front();
            q.pop();

            // current = (node, (x,y))

            // first of outer pair = TreeNode*
            TreeNode* node = current.first;

            // second of outer pair = (x,y)
            // first of inner pair = x
            int x = current.second.first;

            // second of inner pair = y
            int y = current.second.second;

            // Store current node at its (x,y) position
            // Example:
            // nodes[0][2].insert(5);
            nodes[x][y].insert(node->val);

            // Left child
            // Move LEFT  -> x - 1
            // Move DOWN  -> y + 1
            if (node->left) {
                q.push({node->left, {x - 1, y + 1}});
            }

            // Right child
            // Move RIGHT -> x + 1
            // Move DOWN  -> y + 1
            if (node->right) {
                q.push({node->right, {x + 1, y + 1}});
            }
        }

        vector<vector<int>> answer;

        // Traverse columns from left to right
        for (auto column : nodes) {

            vector<int> currentColumn;

            // Traverse rows from top to bottom
            for (auto row : column.second) {

                // Add all values from multiset
                // (already sorted if multiple nodes
                // are at the same position)
                currentColumn.insert(
                    currentColumn.end(),
                    row.second.begin(),
                    row.second.end()
                );
            }

            answer.push_back(currentColumn);
        }

        return answer;
    }
};