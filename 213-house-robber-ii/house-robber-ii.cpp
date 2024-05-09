class Solution {
public:
    int f(int ind, vector<int>& dp, vector<int>& arr) {
        if (ind == 0)
            return arr[ind];
        if (ind < 1)
            return 0;
        if (dp[ind] != -1)
            return dp[ind];
        int take = arr[ind] + f(ind - 2, dp, arr);
        int notake = f(ind - 1, dp, arr);
        return dp[ind] = max(take, notake);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0]; // If there's only one house, return its value

        // Rob first house, but not last
        vector<int> t1(nums.begin(), nums.end() - 1);
        vector<int> dp(n - 1, -1);
        int one = f(n - 2, dp, t1);

        // Rob last house, but not first
        vector<int> t2(nums.begin() + 1, nums.end());
        dp.assign(n - 1, -1); // Reset dp array
        int two = f(n - 2, dp, t2);

        return max(one, two);
    }
};
