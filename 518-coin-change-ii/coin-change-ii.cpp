class Solution {
public:
long long f(int ind,int t,vector<vector<int>>&dp,vector<int>&coins){
    if(ind==0){
        return (t%coins[ind]==0);
    }
    if(dp[ind][t]!=-1)
    return dp[ind][t];
    long long notpick=f(ind-1,t,dp,coins);
    long long pick=0;
    if(coins[ind]<=t)
    pick=f(ind,t-coins[ind],dp,coins);

    return dp[ind][t]=pick+notpick;
}
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return f(n-1,amount,dp,coins);
    }
};