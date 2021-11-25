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
        int count = 0;
        ListNode* curr = head;
        while(curr != NULL){
            count++;
            curr= curr->next;
        }
        return count;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k == 0 || k == 1){
            return head;
        }
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* fwd = NULL;
        int count = 0;
        int n = length(head);
        while(count < k && curr != NULL){
            fwd = curr->next;
            curr->next = prev;
            prev = curr;
            curr = fwd;
            count++;
        }
        n = n-k;
        if(k < n || k == n){
            head->next = reverseKGroup(fwd,k);
        }
        else if(fwd != NULL){
            head->next = fwd;
        }
        return prev;
    }
};