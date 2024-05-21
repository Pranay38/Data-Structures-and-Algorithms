class Solution {
public:
int f(int ind,int buy,vector<int>&prices,vector<vector<int>>&dp,int n){
    if(ind>=n)
    return 0;
    if(dp[ind][buy]!=-1)
    return dp[ind][buy];
    int profit;
    if(buy==0){
        int nt=0+f(ind+1,0,prices,dp,n);
        int b=-prices[ind]+f(ind+1,1,prices,dp,n);
        profit=max(nt,b);
    }
    else if(buy==1){
        int nt2=0+f(ind+1,1,prices,dp,n);
        int s=prices[ind]+f(ind+2,0,prices,dp,n);
        profit=max(nt2,s);
    }
    return dp[ind][buy]=profit;
}
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return f(0,0,prices,dp,n);
    }
};