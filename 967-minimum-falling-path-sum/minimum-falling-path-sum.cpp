class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int j=0;j<n;j++){
            dp[0][j]=matrix[0][j];
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                int up=matrix[i][j]+dp[i-1][j];
                int ldiag=matrix[i][j];
                if(j-1>=0)
                ldiag+=dp[i-1][j-1];
                else
                ldiag+=1e9;
                int rdiag=matrix[i][j];
                if(j+1<n)
                rdiag+=dp[i-1][j+1];
                else
                rdiag+=1e9;
                dp[i][j]=min(up,min(ldiag,rdiag));
            }
           
        }
        int mini=INT_MAX;
        for(int j=0;j<n;j++){
            mini=min(mini,dp[n-1][j]);
        }
        return mini;
    }
};