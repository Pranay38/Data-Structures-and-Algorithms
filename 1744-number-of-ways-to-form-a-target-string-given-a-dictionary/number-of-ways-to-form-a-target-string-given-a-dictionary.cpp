#define MOD 1000000007
class Solution {
public:
    int numWays(vector<string>& words, string target) {
        int m=words.size(),n=words[0].size(),t_len=target.size();
    vector<vector<int>>freq(n,vector<int>(26,0));
    for(int j=0;j<m;j++)
        for(int k=0;k<n;k++)
            freq[k][words[j][k]-'a']++;
    vector<long long>dp(t_len+1,0);
    dp[0]=1;
    for(int k=0;k<n;k++){
        for(int i=t_len-1;i>=0;i--){
            dp[i+1]=(dp[i+1]+dp[i]*freq[k][target[i]-'a'])%MOD;
        }
    }
    return dp[t_len];

    }
};