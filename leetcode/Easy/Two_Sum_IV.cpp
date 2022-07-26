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
    
    void inorder(TreeNode* root){
        if(!root) return;
        inorder(root->left);
        output.push_back(root->val);
        inorder(root->right);
    }
    
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        inorder(root);
        int i = 0;
        int j = output.size() - 1;
        while(i < j){
            if(output[i] + output[j] == k) return true;
            else if((output[i] + output[j]) < k) i++;
            else j--;
        }
        return false;
    }
};