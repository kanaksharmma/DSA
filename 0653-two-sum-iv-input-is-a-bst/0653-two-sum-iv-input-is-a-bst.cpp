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

class BSTIterator {
    stack<TreeNode *> myStack;
    // reverse = true : before 
    // reverse = false : next 
    bool reverse = true;
public:
    BSTIterator(TreeNode *root, bool isReverse){
        reverse = isReverse;
        pushAll(root);
    }    

    // return whether we have a next smallest number 
    bool hasNext(){
        return !myStack.empty();
    }

    // return the next smallest number 
    int next(){
        TreeNode *tmpNode = myStack.top();
        myStack.pop();
        if(!reverse) pushAll(tmpNode->right); // next: go store all left
        else pushAll(tmpNode->left); // before : go store all right 
        return tmpNode->val;
    }

private:
    void pushAll(TreeNode *node){
        for(;node != NULL; ){
            myStack.push(node);
            if(reverse == true){
                node = node->right;
            } else{
                node = node->left;
            }
        }
    }
}; 
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        BSTIterator l(root, false ); // for next
        BSTIterator r(root, true ); // for before

        int i = l.next();
        int j = r.next(); //iteratot of before
        while(i<j){
            if(i + j == k) return true;
            else if(i + j < k) i = l.next();
            else j = r.next();
        }
        return false;
    }
};