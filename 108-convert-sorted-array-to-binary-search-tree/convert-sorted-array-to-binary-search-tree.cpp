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
TreeNode* f(vector<int>&nums,int begin,int end ){
    if(begin>end)
    return NULL;
    int mid=begin+(end-begin)/2;
    TreeNode* root=new TreeNode(nums[mid]);
    root->left=f(nums,begin,mid-1);
    root->right=f(nums,mid+1,end);
    return root;
} 
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n=nums.size();
       return f(nums,0,n-1); 
    }  
};