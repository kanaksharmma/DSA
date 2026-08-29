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
private:
    TreeNode* first;// for 1st violation
    TreeNode* prev; // for storing prev value ( for comapring)
    TreeNode* middle; // for adjacent violation 
    TreeNode* last; // for non adjacent 2nd violation

private:
    void inorder(TreeNode* root){
        if(root == NULL) return;

        inorder(root->left);

        if (prev != NULL && (root->val < prev->val)){
            
            // first violation : mark the two adjacentnodes as first and middle 
            if(first==NULL){
                first = prev;
                middle = root;
            }
            
            // in case of non adjacent nodes this is 2nd violation, mark the node as last 
            else
                last = root;
        }
        
        // mark this node as previous 
        prev = root;
        inorder(root->right);
    }
public:
    void recoverTree(TreeNode* root) {
        first = middle = last = NULL;
        prev = new TreeNode(INT_MIN);
        inorder(root);
        if(first && last) swap(first->val, last->val);
        else if (first && middle) swap(first->val, middle->val);
        
    }
};