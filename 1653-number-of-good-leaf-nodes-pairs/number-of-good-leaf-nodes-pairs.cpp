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
private:
    void preorder(TreeNode* &root){
        if(root->left==NULL && root->right==NULL){
            leaf.push_back(root);
        }
        if(root->left){
            parent[root->left]=root;
            preorder(root->left);
        }
        if(root->right){
            parent[root->right]=root;
            preorder(root->right);
        }
    }
void solve(TreeNode* &root,unordered_map<TreeNode*,int> &tempvis,int &distance,int i){
    if(i>distance){
        return;
    }
    if(i<=distance && root->left==NULL && root->right==NULL && vis[root]!=1){
        cout<<root->val<<' ';
        tempvis[root]=1;
        ans+=1;
        return;
    }
    tempvis[root]=1;
    if(parent[root] && tempvis[parent[root]]!=1){
        solve(parent[root],tempvis,distance,i+1);
    }
    if(root->left && tempvis[root->left]!=1){
        solve(root->left,tempvis,distance,i+1);
    }
    if(root->right && tempvis[root->right]!=1){
        solve(root->right,tempvis,distance,i+1);
    }
}
public:
int ans=0;
unordered_map<TreeNode*,TreeNode*> parent;
vector<TreeNode*> leaf;
unordered_map<TreeNode*,int> vis;
    int countPairs(TreeNode* root, int distance) {
        preorder(root);
        for(int i=0;i<leaf.size();i++){
            unordered_map<TreeNode*,int> vistemp;
            cout<<leaf[i]->val<<" ";
            vis[leaf[i]]=1;
            vistemp[leaf[i]]=1;
            solve(leaf[i],vistemp,distance,0);
            cout<<endl;
        }
        return ans;
    }
    
};