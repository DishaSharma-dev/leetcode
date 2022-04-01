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
    vector<int> output;
    vector<int> postorderTraversal(TreeNode* root) {
        if(root == NULL) return output;
        if(root->left != NULL) postorderTraversal(root->left);
        if(root->right != NULL) postorderTraversal(root->right);
        output.push_back(root->val);
        return output;
    }
};