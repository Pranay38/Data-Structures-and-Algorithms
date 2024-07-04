class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int>mp;
        int n=nums.size();
        for(int i=0;i<n;i++)
        mp[nums[i]]++;
        int mval=INT_MIN;
        for(auto it:mp){
            mval=max(mval,it.second);
        }
        int c=0;
        for(auto it:mp){
            if(it.second==mval)
            c+=it.second;
        }
        return c;
    }
};