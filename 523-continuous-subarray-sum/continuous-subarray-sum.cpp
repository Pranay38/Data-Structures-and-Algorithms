class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int prev=0;
        int sum=0;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            prev+=nums[i];
            prev%=k;
            if(mp.find(prev)!=mp.end())
            return true;
            mp[sum]++;
            sum=prev;
        }
        return false;

    }
};