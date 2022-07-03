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
    
    bool hasSum(TreeNode* root, int targetSum){
        if(root == NULL) return false;
        if(!root->left && !root->right && targetSum-root->val == 0) return true;
        return (hasSum(root->left, targetSum - root->val) ||  hasSum(root->right, targetSum - root->val));
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        return hasSum(root, targetSum);
    }
};