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

    // Delete a node from BST
    TreeNode* deleteNode(TreeNode* root, int key) {

        // Empty tree
        if (root == NULL) return NULL;

        // If root itself is the node to delete
        if (root->val == key)
            return helper(root);

        TreeNode* dummy = root;   // Save original root

        // Find the parent of the node to delete
        while (root != NULL) {

            // Move to left side
            if (key < root->val) {

                // Found the node on left
                if (root->left != NULL && root->left->val == key) {
                    root->left = helper(root->left);
                    break;
                }

                root = root->left;
            }

            // Move to right side
            else {

                // Found the node on right
                if (root->right != NULL && root->right->val == key) {
                    root->right = helper(root->right);
                    break;
                }

                root = root->right;
            }
        }

        return dummy;
    }

    // Handles deletion cases
    TreeNode* helper(TreeNode* root) {

        // Case 1: No left child
        if (root->left == NULL)
            return root->right;

        // Case 2: No right child
        if (root->right == NULL)
            return root->left;

        // Case 3: Both children exist
        TreeNode* rightChild = root->right;

        // Find the largest node in left subtree
        TreeNode* lastRight = findLastRight(root->left);

        // Attach right subtree there
        lastRight->right = rightChild;

        // Return new root of this subtree
        return root->left;
    }

    // Returns the rightmost node of a subtree
    TreeNode* findLastRight(TreeNode* root) {

        while (root->right != NULL)
            root = root->right;

        return root;
    }
};