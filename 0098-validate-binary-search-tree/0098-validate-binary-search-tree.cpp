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

    // Check if tree is a valid BST
    bool isValidBST(TreeNode* root) {
        return checkBST(root, LLONG_MIN, LLONG_MAX);
    }

    // Check if node lies within valid range
    bool checkBST(TreeNode* root, long long minValue, long long maxValue) {

        // Empty tree is valid
        if (root == NULL)
            return true;

        // Node must be inside the range!!  if not return false 
        if (root->val <= minValue || root->val >= maxValue)
            return false;

        // Left values must be smaller
        // Right values must be greater
        return checkBST(root->left, minValue, root->val) &&
               checkBST(root->right, root->val, maxValue);
    }
};