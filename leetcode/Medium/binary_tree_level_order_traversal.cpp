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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == NULL)
            return {};
        queue<TreeNode*> q;
        vector<vector<int>> result;
        q.push(root);
        TreeNode* temp;
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
            result.push_back(v);
        }
        return result;
    }
};