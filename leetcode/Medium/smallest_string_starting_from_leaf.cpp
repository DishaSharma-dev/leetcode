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
    
    string ans = "zzz";
    void solve(TreeNode* root, string s){
        if(!root->left && !root->right){
            s += root->val + 'a';
            reverse(s.begin(), s.end());
            if(s < ans && s.length() > 1) ans = s;
            return;
        }
        s += (root->val + 'a');
        if(root->left)solve(root->left, s);
        if(root->right)solve(root->right, s);
    }
    
    string smallestFromLeaf(TreeNode* root) {
        if(!root) return "";
        if(!root->left && !root->right){
            string s = "";
            s += root->val + 'a';
            return s;
        }
        string s = "";
        solve(root, s);
        return ans;
    }
};