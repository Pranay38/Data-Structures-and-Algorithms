class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int>mp;
        int c=0;
        int l=0,n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==1)
            c++;
            else if(nums[i]==0)
            c--;
            if(c==0)
            l=i+1;
            if(mp.find(c)!=mp.end())
            l=max(l,i-mp[c]);
            else
            mp[c]=i;
        }
        return l;
    }
};