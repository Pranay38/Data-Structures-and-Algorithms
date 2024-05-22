class Solution {
public:
    int f(int ind, int prev_index, vector<int>& nums, vector<vector<int>>& dp, int n) {
        if (ind == n)
            return 0;
        if (dp[ind][prev_index + 1] != -1)
            return dp[ind][prev_index + 1];

        int notpick = f(ind + 1, prev_index, nums, dp, n);
        int pick = 0;
        if (prev_index == -1 || nums[prev_index] < nums[ind]) {
            pick = 1 + f(ind + 1, ind, nums, dp, n);
        }
        return dp[ind][prev_index + 1] = max(pick, notpick);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return f(0, -1, nums, dp, n); 
    }
};
