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
bool f(TreeNode* root){
    if(root-> val==0||root->val==1)
    return root->val==1;
    else if(root->val==2)
    return f(root->left)||f(root->right);
    else if(root->val==3)
    return f(root->left)&&f(root->right);
    else 
    return false;
}
    bool evaluateTree(TreeNode* root) {
        return f(root);
    }
};