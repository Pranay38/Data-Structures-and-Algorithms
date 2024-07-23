class Solution {
public:
static bool f(pair<int,int>&a,pair<int,int>&b){
    if(a.first<b.first)
    return true;
    else if(a.first==b.first){
        if(a.second>b.second)
        return true;
        return false;
    }
    return false;
}
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto it:nums)
        mp[it]++;
        vector<pair<int,int>>v;
        for(auto it:mp){
            v.push_back({it.second,it.first});
        }
        sort(v.begin(),v.end(),f);
        vector<int>ans;
        for(auto it:v){
            int freq=it.first;
            int val=it.second;
            while(freq--)
            ans.push_back(val);
        }
        return ans;

        
    }
};