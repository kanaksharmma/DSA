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
        // x-coordinate -> y-coordinate -> all node values at that position
        map<int, map<int, multiset<int>>> nodes;

        // Queue stores:
        // {node, {x, y}}
        queue<pair<TreeNode*, pair<int, int>>> q;

        // Root starts at (0,0)
        q.push({root, {0, 0}});

        // Normal BFS traversal
        while (!q.empty()) {

            // Take the front element
            auto current = q.front();
            q.pop();

            TreeNode* node = current.first;

            // Get x (vertical) and y (level)
            int x = current.second.first;
            int y = current.second.second;

            // Store node value at its position
            // multiset automatically keeps values sorted
            nodes[x][y].insert(node->val);

            // Left child:
            // Move one column left (x-1)
            // Move one level down (y+1)
            if (node->left) {
                q.push({node->left, {x - 1, y + 1}});
            }

            // Right child:
            // Move one column right (x+1)
            // Move one level down (y+1)
            if (node->right) {
                q.push({node->right, {x + 1, y + 1}});
            }
        }

        vector<vector<int>> answer;

        // Traverse columns from left to right
        for (auto column : nodes) {

            vector<int> currentColumn;

            // Traverse levels from top to bottom
            for (auto level : column.second) {

                // Add all values stored in multiset
                currentColumn.insert(currentColumn.end(),
                                     level.second.begin(),
                                     level.second.end());
            }

            answer.push_back(currentColumn);
        }

        return answer;
    }
};