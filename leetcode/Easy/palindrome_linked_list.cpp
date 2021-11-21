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
    
    ListNode* mid(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL  && fast->next != NULL){
            slow = slow->next;
            fast  = fast->next->next;
        }
        return slow;
    }
    
public:
    bool isPalindrome(ListNode* head) {
        if(head->next == NULL){
            return head;
        }
         ListNode* midValue = mid(head);
         ListNode* last = reverse(midValue);
         ListNode* current = head;
         while(last != NULL){
             if(current->val != last->val){
                 return false;
             }
             current = current->next;
             last = last->next;
         }
        return true;
    }
};