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
    // Public because LeetCode calls this function from outside the class.
    // This is the main function that returns the diameter of the tree.
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;

        // Call the helper function to calculate heights
        // and update the diameter.
        height(root, diameter);

        return diameter;
    }

private:
    // Private because this is only a helper function.
    // It is not meant to be called directly from outside the class.
    int height(TreeNode* node, int& diameter) {

        // Base case: height of an empty tree is 0.
        if (node == nullptr)
            return 0;

        // Calculate height of left subtree.
        int leftHeight = height(node->left, diameter);

        // Calculate height of right subtree.
        int rightHeight = height(node->right, diameter);

        // Diameter passing through the current node
        // = left subtree height + right subtree height.
        diameter = max(diameter, leftHeight + rightHeight);

        // Return the height of the current node.
        return 1 + max(leftHeight, rightHeight);
    }
};  
