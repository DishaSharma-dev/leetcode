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
    
    bool isBST(TreeNode* root, long int minValue, long int maxValue){
        if(!root) return true;
        if(root->val <= minValue || root->val >= maxValue) return false;
        return isBST(root->left, minValue, root->val) and isBST(root->right, root->val, maxValue);
    }
    
    bool isValidBST(TreeNode* root) {
        if(!root->left && !root->right) return true;
        return isBST(root, -100000000000, 100000000000);
    }
};