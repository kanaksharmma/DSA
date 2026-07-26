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

 // left right root
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {

        vector<int> post;          // Stores the final postorder traversal
        stack<TreeNode*> st;       // Stack to simulate recursion

        TreeNode* cur = root;      // Start from the root

        while (cur != NULL || !st.empty()) {

            // Step 1: Go as left as possible
            if (cur != NULL) {
                st.push(cur);      // Save current node
                cur = cur->left;   // Move to left child
            }

            // Step 2: Left subtree is finished
            else {

                // Check the right child of the top node
                TreeNode* temp = st.top()->right;

                // If right child doesn't exist,
                // then this node is ready to be processed
                if (temp == NULL) {

                    temp = st.top();
                    st.pop();

                    post.push_back(temp->val);

                    // After processing a node,
                    // keep popping while we are coming back
                    // from the right subtree.
                    while (!st.empty() && temp == st.top()->right) {

                        temp = st.top();
                        st.pop();

                        post.push_back(temp->val);
                    }
                }

                // Right subtree still needs to be traversed
                else {
                    cur = temp;
                }
            }
        }

        return post;
    }
};