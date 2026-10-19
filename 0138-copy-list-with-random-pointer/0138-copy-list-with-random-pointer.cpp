/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/


class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) {
            return NULL;
        }

        // Step 1: Insert copied nodes between original nodes
        Node* temp = head;

        while (temp != NULL) {
            Node* copy = new Node(temp->val);
            copy->next = temp->next;
            temp->next = copy;
            temp = copy->next;
        }

        // Step 2: Connect random pointers
        temp = head;

        while (temp != NULL) {
            Node* copy = temp->next;

            if (temp->random != NULL) {
                copy->random = temp->random->next;
            } else {
                copy->random = NULL;
            }

            temp = copy->next;
        }

        // Step 3: Separate original and copied lists
        temp = head;
        Node* dummy = new Node(-1);
        Node* copyTail = dummy;

        while (temp != NULL) {
            Node* copy = temp->next;
            Node* nextOriginal = copy->next;

            copyTail->next = copy;
            copyTail = copy;

            temp->next = nextOriginal;
            temp = nextOriginal;
        }

        Node* newHead = dummy->next;
        delete dummy;

        return newHead;
    }
};
