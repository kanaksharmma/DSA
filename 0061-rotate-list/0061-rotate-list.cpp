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
    ListNode* findNthLastNode(ListNode* temp, int k){
        int cnt = 1 ;
        while(temp!=NULL){
            if(cnt == k) return temp;
            cnt ++;
            temp = temp ->next;

        }
        return temp;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || k == 0) return head;
        ListNode* tail = head;
        int len = 1;
        while(tail->next != NULL){
            tail = tail->next;
            len +=1;
        }
        

        if(k % len == 0)  return head; // same configuration 

        k = k % len;// if k > length 

        ListNode* newLastNode = findNthLastNode(head, len-k);
        tail -> next = head;// attach the current last node to current head 

        head = newLastNode -> next;//update head
        newLastNode -> next = NULL;// make the last node point to null

        return head;
        
    }
};