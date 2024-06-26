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
    void dfs(TreeNode* node, vector<int>& vals)
    {
        if( node == nullptr ) return;
        dfs(node->left,vals);
        vals.push_back(node->val);
        dfs(node->right,vals);
    }
    TreeNode* make_tree(vector<int>& vals,int s,int e){
        if( s >= e ) return nullptr;
        int mid = s+(e-s)/2;
        TreeNode* root = new TreeNode(vals[mid]);
        root->left = make_tree(vals, s,mid);
        root->right = make_tree(vals, mid+1,e);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> vals;
        dfs(root,vals);
        if( vals.size() == 0 ) return nullptr;
        sort(vals.begin(),vals.end());
        return make_tree(vals,0,vals.size());
    }
};