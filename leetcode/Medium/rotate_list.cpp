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
    int length(ListNode* head){
        ListNode* curr = head;
        int count = 0;
        while(curr != NULL){
            curr = curr->next;
            count++;
        }
        return count;
    }
    
    ListNode* reverse(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = NULL;
        while(curr != NULL){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(k == 0  || head == NULL || head->next == NULL){
            return head;
        }
        int len = length(head );
        if(k == len){
            return head;
        }
        k = k % len;
        if(k == 0){
            return head;
        }
        ListNode* head1 = reverse(head);
        ListNode* tail1 = NULL;
        ListNode* curr = head1;
        int count = 0;
        while(count < k && curr != NULL){
            if(tail1 == NULL){
                tail1 = curr;
                curr = curr->next;
                count++;
            }
            else{
                tail1->next = curr;
                tail1 = tail1->next;
                curr = curr->next;
                count++;
            }
        }
        tail1->next = NULL;
        ListNode* head2 = curr;
        ListNode* newhead1 = reverse(head1);
        ListNode* newhead2 = reverse(head2);
        head1->next = newhead2;
        return newhead1;
    }
};