class Solution {
    #define ll long long
public:
ll f(vector<ll>&dp,vector<int>&power,unordered_map<int,int>&mp,vector<int>&t,int ind){
    int n=power.size();
    if(ind>=n)
    return 0;
    if(dp[ind]!=-1)
    return dp[ind];
    ll notpick=f(dp,power,mp,t,ind+1);
    ll pick=0;
    ll nind=ind+1;
    while(nind<n&&power[nind]-power[ind]<=2)
    nind++;
    pick=(1ll)*mp[t[ind]]*t[ind]+f(dp,power,mp,t,nind);
    return dp[ind]=max(pick,notpick);

}
    long long maximumTotalDamage(vector<int>& power) {
        vector<int>t(power);
        sort(t.begin(),t.end());
        t.resize(unique(t.begin(),t.end())-t.begin());
        unordered_map<int,int>mp;
        for(auto it:power){
            mp[it]++;
        }
        vector<ll>dp(t.size(),-1);
        return f(dp,t,mp,t,0);

    }
};
