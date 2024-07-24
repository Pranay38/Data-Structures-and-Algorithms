class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        unordered_map<int,int>mp;
        int n=nums.size();
        vector<pair<int,int>>v(n);
        for(int i=0;i<n;i++){
            int og=nums[i];
            int mapped;
            if(og==0)
            mapped=mapping[0];
            else
            mapped=0;
            int p=1;
            while(og>0){
                int d=og%10;
                mapped+=p*mapping[d];
                og/=10;
                p*=10;
            }
            v[i]={mapped,i};
        }
        sort(v.begin(),v.end());
        vector<int>ans;
        for(auto it:v){
            ans.push_back(nums[it.second]);
        }
        return ans;

    }
};