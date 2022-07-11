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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> m;
        queue<pair<TreeNode*, pair<int, int>>> q;
        if(root == NULL) return {};
        q.push({root, {0, 0}});
        while(!q.empty()){
            TreeNode* front = q.front().first;
            int line = q.front().second.first;
            int level = q.front().second.second;
            q.pop();
            m[line][level].insert(front->val);
            if(front->left) q.push({front->left, {line -1, level + 1}});
            if(front->right) q.push({front->right, {line + 1, level + 1}});
        }
        vector<vector<int>> output;
        for(auto it : m){
           vector<int> col;
            for(auto x : it.second){
                col.insert(col.end(), x.second.begin(), x.second.end());
            }
            output.push_back(col);
        }
        return output;
    }
};