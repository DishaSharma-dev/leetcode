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
    int cnt = 0;
    int count(TreeNode* root){
        if(root == NULL) return cnt;
        if(root->left) cnt = 1 + count(root->left);
        if(root->right) cnt = 1 + count(root->right);
        return cnt;
    }
    
    int countNodes(TreeNode* root) {
        if(root == NULL) return 0;
        return 1 + count(root);
    }
};