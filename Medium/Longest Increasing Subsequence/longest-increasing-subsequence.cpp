//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
        vector<int>ans;
        ans.push_back(a[0]);
        int c=1;
        for(int i=1;i<n;i++){
            if(a[i]>ans.back()){
                ans.push_back(a[i]);
                c++;
            }
            else{
                int b=lower_bound(ans.begin(),ans.end(),a[i])-ans.begin();
                ans[b]=a[i];
            }
        }
        return c;
       // your code here
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends