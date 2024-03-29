class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long maxi=-1e9;
        for(int i=0;i<nums.size();i++)
        {
            if(maxi<nums[i])
            maxi=nums[i];
        }
        long long count=0;
        long long maxi_count=0;
        long long i=0,j=0;
        while(j<nums.size()&&i<=j)
        {
            
          if(nums[j]==maxi)
          {
          maxi_count++;
          }
          while(maxi_count>=k)
          {
            if(nums[i]==maxi)
            maxi_count--;
            i++;
            count+=nums.size()-j;
          }
          j++;

        }
        return count;
    }
};