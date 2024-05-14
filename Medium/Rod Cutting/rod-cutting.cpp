//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
  int f(int ind,int n,vector<vector<int>>&dp,int price[]){
      if(ind==0)
      return n*price[ind];
      if(dp[ind][n]!=-1)
      return dp[ind][n];
      int notpick=0+f(ind-1,n,dp,price);
      int pick=INT_MIN;
      int rl=ind+1;
      if(rl<=n){
          pick=price[ind]+f(ind,n-rl,dp,price);
      }
      return dp[ind][n]=max(pick,notpick);
  }
    int cutRod(int price[], int n) {
        //code here
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return f(n-1,n,dp,price);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends