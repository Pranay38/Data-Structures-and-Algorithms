//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
int f(int ind,int w,vector<vector<int>>&dp,int wt[],int val[]){
    if(ind==0)
    return ((w/wt[ind])*val[ind]);
    if(dp[ind][w]!=-1)
    return dp[ind][w];
    int notpick=0+f(ind-1,w,dp,wt,val);
    int pick=INT_MIN;
    if(wt[ind]<=w){
        pick=val[ind]+f(ind,w-wt[ind],dp,wt,val);
    }
    return dp[ind][w]=max(pick,notpick);
    
}
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        vector<vector<int>>dp(N,vector<int>(W+1,-1));
        return f(N-1,W,dp,wt,val);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends