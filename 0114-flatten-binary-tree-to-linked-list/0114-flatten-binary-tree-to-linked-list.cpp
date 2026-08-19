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
    void flatten(TreeNode* root) {

        // Start from root
        TreeNode* curr = root;

        while (curr != NULL) {

            // If left subtree exists
            if (curr->left != NULL) {

                // Find the rightmost node of left subtree
                TreeNode* prev = curr->left;

                while (prev->right != NULL) {
                    prev = prev->right;
                }

                // Attach right subtree to left subtree
                prev->right = curr->right;

                // Move left subtree to right
                curr->right = curr->left;

                // Remove left pointer
                curr->left = NULL;
            }

            // Move to next node
            curr = curr->right;
        }
    }
};