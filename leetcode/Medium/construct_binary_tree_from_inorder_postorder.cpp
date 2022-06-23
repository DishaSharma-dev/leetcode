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
    
    TreeNode* tree(vector<int>& preorder, vector<int>& inorder, int ins, int ine, int pres, int pree){
        if(ins > ine) return NULL;
        int rootData = preorder[pres];
        int rootIndex;
        for(int i = ins; i <= ine; i++){
            if(inorder[i] == rootData){
                rootIndex = i;
                break;
            }
        }
        int LIS = ins;
        int LIE = rootIndex - 1;
        int LPS = pres + 1;
        int LPE = LPS + LIE - LIS;
        int RIS = rootIndex + 1;
        int RIE = ine;
        int RPS = LPE + 1;
        int RPE = pree;
        TreeNode* root = new TreeNode(rootData);
        root->left = tree(preorder, inorder, LIS, LIE, LPS, LPE);
        root->right = tree(preorder, inorder, RIS, RIE, RPS, RPE);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        return tree(preorder, inorder, 0, n-1, 0, n-1);
    }
};