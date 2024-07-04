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
bool fun(TreeNode* root, int c,int targetSum){
    if(root==NULL)
    return false;
    c+=root->val;
    if(root->left==NULL&&root->right==NULL)
    return (c==targetSum);
    bool l=fun(root->left,c,targetSum);
    bool r=fun(root->right,c,targetSum);
    return l||r;
}
    bool hasPathSum(TreeNode* root, int targetSum) {
        return fun(root,0,targetSum);
    }
};