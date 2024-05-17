class Solution {
public:
    int f(int ind1, int ind2, string s1, string s2, vector<vector<int>>& dp) {
        if (ind2 == 0) return 1; // Base case
        if (ind1 == 0) return 0; // Base case
        if (dp[ind1][ind2] != -1) return dp[ind1][ind2];
        int ans = 0;
        if (s1[ind1 - 1] == s2[ind2 - 1]) {
            int leave = f(ind1 - 1, ind2 - 1, s1, s2, dp);
            int stay = f(ind1 - 1, ind2, s1, s2, dp);
            ans = (leave + stay) % mod;
        }
        else {
            ans = f(ind1 - 1, ind2, s1, s2, dp);
        }
        dp[ind1][ind2] = ans;
        return ans;
    }
    
    int mod = 1e9 + 7;
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return f(n, m, s, t, dp);
    }
};
