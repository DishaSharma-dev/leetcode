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
    int sum = 0;
    int longestPath(TreeNode* root, int prev){
        if(!root) return 0;
        int left = longestPath(root->left, root->val);
        int right = longestPath(root->right, root->val);
        sum  = max(sum, left + right);
        if(root->val == prev){
            return 1 + max(left, right);
        } 
        else return 0;
    }
    
    int longestUnivaluePath(TreeNode* root) {
        longestPath(root, 0);
        return sum;
    }
};