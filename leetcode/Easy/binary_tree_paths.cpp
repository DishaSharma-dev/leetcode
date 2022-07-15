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
    vector<string> str;
    void path(TreeNode* root, string output){
        if(!root) return;
        if(!root->left && !root->right){
            if(output == "") output += to_string(root->val);
            else output += "->" + to_string(root->val);
            str.push_back(output);
            return;
        }
        if(output == "") output += to_string(root->val);
        else output += "->" + to_string(root->val);
        path(root->left, output);
        path(root->right, output);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root) return str;
        string output;
        path(root, "");
        return str;
    }
};