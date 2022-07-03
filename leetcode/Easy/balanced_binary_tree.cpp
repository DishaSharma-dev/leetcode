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
    int found = true;
    int checkHeight(TreeNode* root){
        if(root == NULL) return 0;
        int op1, op2;
        op1 = 1 + checkHeight(root->left); 
        op2 = 1 + checkHeight(root->right);
        if(abs(op1 - op2) > 1) {
            found = false;
        }
        return max(op1, op2);
    }
    
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        checkHeight(root);
        return found;
    }
};