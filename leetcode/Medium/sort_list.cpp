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
    ListNode* mergeSort(ListNode* L1, ListNode* L2){
        ListNode* ptr = new ListNode(0);
        ListNode* curr = ptr;
        while(L1 != NULL && L2 != NULL){
            if(L1->val < L2->val){
                curr->next = L1;
                L1 = L1->next;
                curr = curr->next;
            }
            else{
                curr->next = L2;
                L2 = L2->next;
                curr = curr->next;
            }
        }
        while(L1 != NULL){
            curr->next = L1;
            L1 = L1->next;
            curr = curr->next;
        }
        while(L2 != NULL){
            curr->next = L2;
            L2 = L2->next;
            curr = curr->next;
        }
        curr->next = NULL;
        return ptr->next;
    }
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode* temp = NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL){
            temp = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        temp->next = NULL;
        ListNode* L1 = sortList(head);
        ListNode* L2 = sortList(slow);
        return mergeSort(L1, L2);
    }
};