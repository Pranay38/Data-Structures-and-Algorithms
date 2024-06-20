class Solution {
public:
int f(vector<vector<int>>&dp,int n,vector<int>&rewardValues,int ind,int reward){
    if(ind==n)
    return reward;
    if(dp[ind][reward]!=-1)
    return dp[ind][reward];
    int notpick=0+f(dp,n,rewardValues,ind+1,reward);
    int pick=0;
    if(reward<rewardValues[ind])
    pick=f(dp,n,rewardValues,ind+1,reward+rewardValues[ind]);
    return dp[ind][reward]=max(pick,notpick);
}
    int maxTotalReward(vector<int>& rewardValues) {
        sort(rewardValues.begin(),rewardValues.end());
        int n=rewardValues.size();
        vector<vector<int>>dp(n,vector<int>(4001,-1));
        return f(dp,n,rewardValues,0,0);
    }
};