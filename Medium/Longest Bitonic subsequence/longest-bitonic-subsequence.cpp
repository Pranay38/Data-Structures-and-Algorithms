//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    int LongestBitonicSequence(int n, vector<int> &nums) {
        // code here
        vector<int>dp1(n,1);
        vector<int>dp2(n,1);
        for(int i=0;i<n;i++){
            for(int prev_ind=0;prev_ind<i;prev_ind++){
                if(nums[i]>nums[prev_ind])
                dp1[i]=max(dp1[i],1+dp1[prev_ind]);
            }
        }
        for(int i=n-1;i>=0;i--){
            for(int prev_ind=n-1;prev_ind>i;prev_ind--){
                if(nums[i]>nums[prev_ind])
                dp2[i]=max(dp2[i],1+dp2[prev_ind]);
            }
        }
       // vector<int>ans(n);
        int c=0;
        for(int i=0;i<n;i++){
            if(dp1[i]>1&&dp2[i]>1){
            int p=dp1[i]+dp2[i]-1;
            c=max(p,c);
            }
        }
        return c;
        
        
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        
        vector<int> nums(n);
        Array::input(nums,n);
        
        Solution obj;
        int res = obj.LongestBitonicSequence(n, nums);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends