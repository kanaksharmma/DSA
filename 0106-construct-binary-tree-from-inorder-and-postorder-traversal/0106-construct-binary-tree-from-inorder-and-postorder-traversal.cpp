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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int, int> inordermap;

        for(int i =0; i<inorder.size(); i++){
            inordermap[inorder[i]] = i;
        }

        TreeNode* root = buildTree(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1, inordermap);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, int inStart, int inEnd, vector<int>& postorder, int postStart, int postEnd, map<int, int>& inordermap){
        // if any of the traversal is empty 
        if(postStart > postEnd || inStart > inEnd) return NULL;
        
        // root = last el of postorder
        TreeNode* root = new TreeNode(postorder[postEnd]);

        int inRoot = inordermap[root->val];
        int numsleft = inRoot - inStart; // left side of inorder 

        root->left = buildTree(inorder, inStart, inRoot-1, postorder, postStart, postStart +numsleft-1, inordermap );

        root->right = buildTree(inorder, inRoot + 1, inEnd,  postorder, postStart + numsleft,  postEnd-1, inordermap);

    return root;    
    }
        
    
};