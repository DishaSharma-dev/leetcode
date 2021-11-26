/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL){
            return NULL;
        }
        Node* curr = head;
        while(curr != NULL){
            Node* fwd = curr->next;
            Node* copy = new Node(curr->val);
            curr->next = copy;
            copy->next = fwd;
            curr = fwd;
        }
        Node* p = head;
        while(p != NULL){
            if(p->random == NULL){
                p->next->random = NULL;
            }
            else{
                p->next->random = p->random->next;
            }
            p = p->next->next;
        }
        Node* dummy = new Node(-1);
        Node* temp = dummy;
        Node* mov = head;
        while(mov != NULL){
            temp->next = mov->next;
            mov->next = mov->next->next;
            mov = mov->next;
            temp = temp->next;
        }
        return dummy->next;
    }
};