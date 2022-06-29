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
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL || (head->next == NULL && head->val != val)) return head;
        if(head->next == NULL && head->val == val) return NULL;
        ListNode* temp;
        while(head && head->val == val){
            temp = head->next;
            head = temp;
        }
        if(head == NULL) return head;
        ListNode* curr = head->next;
        ListNode* prev = head;
        while(curr){
            if(curr->val == val){
                prev->next = curr->next;
                curr = curr->next;
            }
            else{
                prev = curr;
                curr = curr->next;
            }
        }
        return head;
    }
};