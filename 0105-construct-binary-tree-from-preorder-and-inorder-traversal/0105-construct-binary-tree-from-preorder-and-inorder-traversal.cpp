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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> inordermap;

        for(int i =0; i<inorder.size(); i++){
            inordermap[inorder[i]] = i;
        }

        TreeNode* root = buildTree(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, inordermap);
        return root;
    }

    TreeNode* buildTree(vector<int> &preorder, int preStart, int preEnd, vector<int>&inorder, int inStart, int inEnd, map<int, int>&  inordermap){
        
        // if any of the traversal is empty 
        if(preStart > preEnd || inStart > inEnd) return NULL;
        
        // root = 1st el of preorder
        TreeNode* root = new TreeNode(preorder[preStart]);

        int inRoot = inordermap[root->val];
        int numsleft = inRoot - inStart; // left side of inorder 

        root->left = buildTree(preorder, preStart + 1, preStart + numsleft, inorder, inStart, inRoot-1, inordermap);

        root->right = buildTree(preorder, preStart + numsleft + 1, preEnd, inorder, inRoot + 1, inEnd, inordermap);

    return root;    
    }
        
    
};