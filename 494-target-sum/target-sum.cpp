class Solution {
public:
int f(int ind,int t,vector<vector<int>>&dp,vector<int>&nums){
    if(ind==0){
        if(t==0&&t==nums[0])
        return 2;
        if(t==0||t==nums[0])
        return 1;
        
        return 0;
    }
    if(dp[ind][t]!=-1)
    return dp[ind][t];
    int notpick=f(ind-1,t,dp,nums);
    int pick=0;
    if(nums[ind]<=t)
    pick=f(ind-1,t-nums[ind],dp,nums);

    return dp[ind][t]=pick+notpick;
}
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum-target<0)
        return 0;
        if((sum-target)%2!=0)
        return 0;

        int s=(sum-target)/2;
        vector<vector<int>>dp(n,vector<int>(s+1,-1));
        return f(n-1,s,dp,nums);

    }
};