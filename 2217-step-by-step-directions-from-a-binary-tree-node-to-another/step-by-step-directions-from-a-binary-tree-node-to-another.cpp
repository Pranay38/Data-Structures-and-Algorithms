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
    bool f(TreeNode* node, int target, vector<string>& path) {
        if (!node)
            return false;
        if (node->val == target)
            return true;
        path.push_back("R");
        if (f(node->right, target, path))
            return true;
        path.pop_back();
        path.push_back("L");
        if (f(node->left, target, path))
            return true;
        path.pop_back();
        return false;
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        vector<string> s, d;
        f(root, startValue, s);
        f(root, destValue, d);
        int c = 0;
        while (c < s.size() && c < d.size() && s[c] == d[c])
            c++;
        vector<string> ans(s.size() - c, "U");
        ans.insert(ans.end(), d.begin() + c, d.end());
        string res;
        for (auto it : ans)
            res += it;
        return res;
    }
};
