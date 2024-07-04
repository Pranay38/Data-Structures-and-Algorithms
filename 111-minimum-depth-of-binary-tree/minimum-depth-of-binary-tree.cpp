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
        if(root==NULL)
        return 0;
        int rd=minDepth(root->right);
        int ld=minDepth(root->left);
        if(rd==0)
        return ld+1;
        if(ld==0)
        return rd+1;
        if(rd<ld)
        return rd+1;
        return ld+1;
    }
};