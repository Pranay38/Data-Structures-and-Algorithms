class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int>ans;
        int n=nums.size();
        vector<bool>p(n+1,false);

        for(int i=0;i<nums.size();i++){
              p[nums[i]]=true;
        }

        
        for(int i=1;i<=nums.size();i++){
            if(!p[i])
            ans.push_back(i);
        }
        return ans;
    }
};