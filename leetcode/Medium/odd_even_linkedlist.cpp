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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode* head1 = NULL;
        ListNode* head2 = NULL;
        ListNode* tail1 = NULL;
        ListNode* tail2 = NULL;
        int count = 0;
        while(head != NULL){
            if(count % 2 == 0){
                if(head1 == NULL){
                    head1 = head;
                    tail1 = head;
                    head = head->next;
                    count++;
                }
                else{
                    tail1->next = head;
                    tail1 = tail1->next;
                    head = head->next;
                    count++;
                }
            }
            else{
                if(head2 == NULL){
                    head2 = head;
                    tail2 = head;
                    head = head->next;
                    count++;
                }
                else{
                    tail2->next = head;
                    tail2 = tail1->next;
                    head = head->next;
                    count++;
                }
            }
        }
        tail1->next = head2;
        tail2->next = NULL;
        return head1;
    }
};