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
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode* temp = head;
        ListNode* prev = NULL;
        ListNode* head1 = NULL;
        ListNode* tail1 = NULL;
        while(temp != NULL){
            if(temp->val < x && temp == head){
                if(head1 == NULL){
                    head1 = temp;
                    tail1 = temp;
                }
                else{
                    tail1->next = temp;
                    tail1 = tail1->next;
                }
                head = temp->next;
                temp = temp->next;
            }
            else if(temp->val < x){
                if(head1 == NULL){
                    head1 = temp;
                    tail1 = temp;
                }
                else{
                    tail1->next = temp;
                    tail1 = tail1->next;
                }
                prev->next = temp->next;
                temp = temp->next;
            }
            else{
                prev = temp;
                temp = temp->next;
            }
        }
        if(head != NULL && head1 != NULL){
            tail1->next = head;
            return head1;
        }
        else if(head == NULL){
            tail1->next =NULL;
            return head1;
        }
        else{
            return head;
        }
        
    }
};