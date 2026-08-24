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
    private: stack<TreeNode* > myStack;
public:
    BSTIterator(TreeNode* root) {
        pushAll(root);
        
    }
    
    int next() {
        TreeNode *tmpNode = myStack.top();
        myStack.pop();
        pushAll(tmpNode->right); // if there exists any right 
        return tmpNode->val;
    }
    
    bool hasNext() {
        return !myStack.empty(); // if stack is not empty return true else false 
        
    }
private:
//this function is responisble to push all the left nodes in the stack 
    void pushAll(TreeNode *node){
        for(; node!=NULL; myStack.push(node), node = node->left);
    }

};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */