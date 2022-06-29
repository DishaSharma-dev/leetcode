/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
       if(root == NULL) return {};
        vector<vector<int>> output;
        output.push_back({root->val});
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int len = q.size();
            vector<int> v;
            for(int i = 0; i < len; i++){
                Node* temp = q.front();
                q.pop();
                for(int i = 0; i < temp->children.size(); i++){
                    q.push(temp->children[i]);
                    v.push_back(temp->children[i]->val);
                }
            }
            if(v.size() != 0)
                output.push_back(v);
        }
        return output;
    }
};