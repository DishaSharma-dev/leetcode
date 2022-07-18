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
    static TreeNode* inSuc(TreeNode* root){
        TreeNode* s = root->right;
        while(s->left){
            s = s->left;
        }
        return s;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;
        if(root->val < key){
            root->right = deleteNode(root->right, key);
        }
        else if(root->val > key){
            root->left = deleteNode(root->left, key);
        }
        else{
            if(!root->left){
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }
            else if(!root->right){
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }
            else{
                TreeNode* temp = inSuc(root);
                swap(root->val, temp->val);
                root->right = deleteNode(root->right, key);
            }
        }
        return root;
    }
};