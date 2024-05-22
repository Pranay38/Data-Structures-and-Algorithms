class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int>dp(n,0);
        vector<int>hash(n,0);
        for(int i=0;i<n;i++){
            hash[i]=i;
            for(int prev_index=0;prev_index<i;prev_index++){
                if(nums[i]%nums[prev_index]==0&1+dp[prev_index]>dp[i]){
                    dp[i]=1+dp[prev_index];
                    hash[i]=prev_index;
                }
            }
        }
        int ans=-1;
        int lastind=1;
        for(int i=0;i<n;i++){
            if(dp[i]>ans){
                ans=dp[i];
                lastind=i;
            }
        }
        vector<int>temp;
        temp.push_back(nums[lastind]);
        while(hash[lastind]!=lastind){
            lastind=hash[lastind];
            temp.push_back(nums[lastind]);
        }
        reverse(temp.begin(),temp.end());
        return temp;

    }
};