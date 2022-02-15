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
    int minDepth(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        int left1 = minDepth(root->left);
        int right1 = minDepth(root->right);
        if(left1 == 0){
            return right1 + 1;
        }
        else if(right1 == 0){
            return left1 + 1;
        }
        else{
            return min(left1, right1) + 1;
        }
    }
};