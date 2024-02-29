class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        if(!root)
            return true;
        queue<TreeNode*> q;
        int cur = 0;
        q.push(root);
        while(!q.empty()){
            int l = q.size();
            int lcur; // Declare lcur here
            if(cur % 2 == 0)
                lcur = INT_MIN;
            else 
                lcur = INT_MAX;
            for(int i = 0; i < l; i++){
                TreeNode* node = q.front();
                q.pop();
                if((cur % 2 == 0 && (node->val % 2 == 0 || node->val <= lcur)) || (cur % 2 == 1 && (node->val % 2 == 1 || node->val >= lcur)))
                    return false;
                lcur = node->val;
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            cur++;
        }
        return true;
    }
};
