/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    ListNode* reverseLinkList(ListNode* head){
        if (head == NULL || head->next == NULL) return head;

        ListNode* newHead = reverseLinkList(head->next);
        ListNode* front = head->next;
        front->next = head;
        head->next = NULL;
        return newHead;
    }
    bool isPalindrome(ListNode* head) {
        if (head==NULL || head->next == NULL) return true;

        ListNode* slow = head;
        ListNode* fast = head;

        // for even : fast wil end at  second last 
        // for odd : fast will end at last node  
        while(fast -> next!=NULL && fast->next->next != NULL){
            slow = slow ->next;
            fast = fast ->next->next;
        }
        ListNode* newHead =  reverseLinkList(slow->next);
        ListNode* first = head;
        ListNode* second = newHead;

        while(second != NULL){
            if(first->val != second->val){
                reverseLinkList(newHead);// return the og conf of LL 
                return false;
            }
            first = first->next;
            second = second->next;
        }
        reverseLinkList(newHead); // return the LL in its orignal configuration
        return true;     
     
    }
};