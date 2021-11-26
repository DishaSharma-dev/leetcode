/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    int length(ListNode* head){
        ListNode* curr = head;
        int count = 0;
        while(curr != 0){
            curr = curr->next;
            count++;
        }
        return count;
    }
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL){
            return NULL;
        }
        int size1 = length(headA);
        int size2 = length(headB);
        int diff = size1 - size2;
        ListNode* temp1 = headA;
        ListNode* temp2 = headB;
        
        if(diff > 0){
            while(diff > 0){
                temp1 = temp1->next;
                diff--;
            }
        }
        else{
            diff = -diff;
            while(diff > 0){
                temp2 = temp2->next;
                diff--;
            }
        }
        while(temp1 != NULL && temp2 != NULL && temp1 != temp2){
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        if(temp1 == temp2){
            return temp1;
        }
        return NULL;
    }
};