class Solution {
public:
    int dp[501][501][26];
    int helper(int ind, int prev, int n, vector<int>& nums, int k){
        if(ind == n)
            return 0;
        if(dp[ind][prev][k] != -1)
            return dp[ind][prev][k];
        int maxi = 0;
        if(prev == 500 || (nums[ind] == nums[prev])){
            maxi = max(maxi, 1 + helper(ind + 1, ind, n, nums, k));
            maxi = max(maxi, helper(ind + 1, prev, n, nums, k));
        }
        else if(nums[ind] != nums[prev]){
            if(k > 0)
                maxi = max(maxi, 1 + helper(ind + 1, ind, n, nums, k - 1));
            maxi = max(maxi, helper(ind + 1, prev, n, nums, k));
        }
        return dp[ind][prev][k] = maxi;
    }
    
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        memset(dp, -1, sizeof(dp));
        return helper(0, 500, n, nums, k);
    }
};