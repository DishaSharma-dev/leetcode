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
    unordered_map<TreeNode*, int> umap;
    int rob(TreeNode* root) {
        if(!root) return 0;
        if(umap[root]) return umap[root];
        int op1 = root->val;
        if(root->left){
            op1 += rob(root->left->left) + rob(root->left->right);
        }
        if(root->right){
            op1 += rob(root->right->left) + rob(root->right->right);
        }
        int op2 = rob(root->left) + rob(root->right);
        umap[root] = max(op1, op2);
        return max(op1, op2);
    }
};