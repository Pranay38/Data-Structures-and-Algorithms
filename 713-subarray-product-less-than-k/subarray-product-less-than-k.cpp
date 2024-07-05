class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int i=0,j=0;
        int n=nums.size();
        int prod=1,ans=0;
        while(j<n){
            prod*=nums[j];
            while(prod>=k&&i<=j){
                prod=prod/nums[i];
                i++;
            }
            ans+=j-i+1;
            j++;
        }
        return ans;
    }
};