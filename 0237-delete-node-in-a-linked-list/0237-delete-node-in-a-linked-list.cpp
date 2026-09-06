/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
    // We cannot directly delete 'node' because we don't have
    // access to the previous node.
    //
    // Example:
    // 1 -> 2 -> 3 -> 4
    //      ^
    //     node
    //
    // Normally, to remove 2, we need to make 1 point to 3.
    // But we don't have the node 1.

    // So, copy the value of the next node (3)
    // into the current node (2).
    //
    // Before:
    // 1 -> 2 -> 3 -> 4
    //
    // After copying:
    // 1 -> 3 -> 3 -> 4
    node->val = node->next->val;


    // Now we skip the next node.
    //
    // node->next currently points to the duplicate 3.
    // node->next->next points to 4.
    //
    // So we make:
    // node -> 4
    //
    // Final list:
    // 1 -> 3 -> 4
    node->next = node->next->next;
}
        
    
};