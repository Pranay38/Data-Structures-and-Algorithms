class Solution {
public:
    int minInsertions(string s) {
        int n=s.size();
        string t=s;
        reverse(s.begin(),s.end());
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        for(int i=0;i<=n;i++){
            dp[i][0]=0;
            dp[0][i]=0;
            
        }
        for(int ind1=1;ind1<=n;ind1++){
            for(int ind2=1;ind2<=n;ind2++){
                if(s[ind1-1]==t[ind2-1])
                dp[ind1][ind2]=1+dp[ind1-1][ind2-1];
                else
                dp[ind1][ind2]=max(dp[ind1-1][ind2],dp[ind1][ind2-1]);
            }
        }
        return (n-dp[n][n]);
    }
};