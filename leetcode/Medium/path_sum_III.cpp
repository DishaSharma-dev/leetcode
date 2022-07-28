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
    int ans = 0;
    void sum(TreeNode* root, vector<int> &path, int targetSum){
        if(!root) return;
        path.push_back(root->val);
        sum(root->left, path, targetSum);
        sum(root->right, path, targetSum);
        long long total = 0;
        for(int i = path.size() - 1; i >= 0; i--){
            total += path[i];
            if(total == targetSum) ans++;
        }
        path.pop_back();
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(!root) return 0;
        vector<int> path;
        sum(root, path, targetSum);
        return ans;
    }
};