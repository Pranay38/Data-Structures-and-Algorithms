class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0,j=0;
        unordered_map<int,int>mp;
        int ans=0;
        while(j<n){
            mp[nums[j]]++;
            if(mp[nums[j]]>k){
                while(nums[i]!=nums[j]){
                    mp[nums[i]]--;
                    i++;
                }
                mp[nums[i]]--;
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};