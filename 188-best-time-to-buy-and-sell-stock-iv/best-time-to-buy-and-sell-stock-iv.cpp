class Solution {
public:
int f(int ind,int buy,int cap,vector<int>&prices,vector<vector<vector<int>>>&dp,int n){
    if(ind==n||cap==0)
    return 0;
    if(dp[ind][buy][cap]!=-1)
    return dp[ind][buy][cap];
    int profit;
    if(buy==0){
        int nt=0+f(ind+1,0,cap,prices,dp,n);
        int b=-prices[ind]+f(ind+1,1,cap,prices,dp,n);
        profit=max(nt,b);
    }
    else if(buy==1){
        int nt2=0+f(ind+1,1,cap,prices,dp,n);
        int s=prices[ind]+f(ind+1,0,cap-1,prices,dp,n);
        profit=max(nt2,s);
    }
    return dp[ind][buy][cap]=profit;
}
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return f(0,0,k,prices,dp,n);
    }
};