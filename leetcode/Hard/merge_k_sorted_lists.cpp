class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int>list;
        for(int i=0; i<lists.size(); i++){
           while(lists[i] != NULL){
               list.push_back(lists[i]->val);
               lists[i]=lists[i]->next;
           }
        }
        
        sort(list.begin(), list.end());
        
        ListNode* ans= new ListNode(0);
        ListNode* result=ans;
        
        for(int i=0; i<list.size(); i++){
            
            ans->next=new ListNode(list[i]);
            ans=ans->next;
        }
        
        return result->next;
    }
};