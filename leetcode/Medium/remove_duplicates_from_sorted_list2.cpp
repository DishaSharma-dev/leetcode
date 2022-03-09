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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL){
            return head;
        }
        ListNode* start = new ListNode(-1);
        ListNode* prev = new ListNode(-1);
        start->next = head;
        prev = start;
        while(head){
            if(head->next && head->next->val == head->val){
                while(head->next && head->next->val == head->val){
                    ListNode* temp = head;
                    head = head->next;
                    delete temp;
                }
                prev->next = head->next;
            }
            else{
                prev = prev->next;
            }
            head = head->next;
        }
        return start->next;
    }
};