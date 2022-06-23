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
    int result = 0;
    void sum(TreeNode* root, int output){
        if(root == NULL) return;
        if(!root->left && !root->right){
            result += root->val;
            result += output * 10;
            return;
        }
        sum(root->left, output*10 + root->val);
        sum(root->right, output*10 + root->val);
    }
    
    int sumNumbers(TreeNode* root) {
       int output = 0;
       sum(root, output);
       return result;
    }
};