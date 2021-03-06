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
    
    int sum;
    void solve(TreeNode* root, bool isleft){
        if(!root) return;
        if(!root->left && !root->right){
            isleft ? sum += root->val : sum = sum;
            return;
        }
        solve(root->left, true);
        solve(root->right, false);
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        sum = 0;
        if(!root) return sum;
        if(!root->left && !root->right) return sum;
        solve(root->left, true);
        solve(root->right, false);
        return sum;
    }
};