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
    bool isSymmetric(TreeNode* root) {
        return root == NULL || isSymmetrical(root->left, root->right);
    }

    bool isSymmetrical(TreeNode* left, TreeNode* right) {
        // If either is NULL
        if (left == NULL || right == NULL)
            return left == right;

        // Compare values
        if (left->val != right->val)
            return false;

        // Compare mirror subtrees
        return isSymmetrical(left->left, right->right) &&
               isSymmetrical(left->right, right->left);
    }
};