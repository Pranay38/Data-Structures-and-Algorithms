class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //int i=0;
        vector<int>t;
                long long sum=0;
        map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            if(mp.find(target-nums[i])!=mp.end()){
                t.push_back(i);
                t.push_back(mp[target-nums[i]]);
            }
            mp[nums[i]]=i;
        }
    
        return t;
    }
};