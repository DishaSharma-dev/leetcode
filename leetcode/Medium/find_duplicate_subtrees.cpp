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
    vector<TreeNode*> output;
    unordered_map<string, int> umap;
    
    string solve(TreeNode* root){
        if(!root) return "$";
        string s = ""; 
        s += to_string(root->val);
        string left = solve(root->left);
        string right = solve(root->right);
        s = s + "$" + left + "$" + right;
        if(umap[s] == 1) output.push_back(root);
        umap[s]++;
        return s;
    }
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        if(!root) return {};
        solve(root);
        return output;
    }
};