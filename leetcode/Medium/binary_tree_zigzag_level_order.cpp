/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == NULL)
            return {};
        queue<TreeNode*> q;
        int flag = 1;
        TreeNode* temp;
        q.push(root);
        vector<vector<int>> ans;
        while(!q.empty()){
            int len = q.size();
            vector<int> v;
            for(int i = 0; i < len; i++){
                temp = q.front();
                q.pop();
                v.push_back(temp->val);
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            if(flag){
                ans.push_back(v);
                  flag = 0;
            }
            else{
                reverse(v.begin(), v.end());
                ans.push_back(v);
                flag = 1;
            }
        }
        return ans;
    }
};