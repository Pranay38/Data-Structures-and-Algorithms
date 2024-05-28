class Solution {
public:
    long long f(int i, int j, int n, int c, vector<int>& cuts, vector<vector<long long>>& dp) {
        if (i > j)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        long long minans = LLONG_MAX;
        for (int ind = i; ind <= j; ind++) {
            long long ans = (long long)cuts[j+1] - cuts[i-1] + f(i, ind-1, n, c, cuts, dp) + f(ind+1, j, n, c, cuts, dp);
            minans = min(minans, ans);
        }
        return dp[i][j] = minans;
    }

    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());
        vector<vector<long long>> dp(c+2, vector<long long>(c+2, 0));
        
        for (int i = c; i >= 1; i--) {
            for (int j = 1; j <= c; j++) {
                if (i > j) continue;
                long long minans = LLONG_MAX;
                for (int ind = i; ind <= j; ind++) {
                    long long ans = (long long)cuts[j+1] - cuts[i-1] + dp[i][ind-1] + dp[ind+1][j];
                    minans = min(minans, ans);
                }
                dp[i][j] = minans;
            }
        }
        return (int)dp[1][c];
    }
};
