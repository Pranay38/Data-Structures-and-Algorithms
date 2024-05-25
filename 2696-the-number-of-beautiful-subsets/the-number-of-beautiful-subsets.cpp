class Solution {
public:
int f(vector<int>&nums,int k,unordered_map<int,int>&mp,int ind,int n){
    if(ind==n)
    return 1;
    int notpick=0+f(nums,k,mp,ind+1,n);
    int pick=0;
    if(!mp[nums[ind]-k]){
        mp[nums[ind]]++;
        pick=f(nums,k,mp,ind+1,n);
        mp[nums[ind]]--;
    }
    int ans=0;
    return pick+notpick;
}
    int beautifulSubsets(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mp;
        sort(nums.begin(),nums.end());
        return f(nums,k,mp,0,n)-1;
    }
};