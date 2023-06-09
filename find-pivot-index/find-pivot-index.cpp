class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        
            int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
    }
    int curr_sum = 0;
    int ans = -1;
    for (int i = 0; i < nums.size(); i++)
    {
        curr_sum += nums[i];
        if (curr_sum == sum)
        {
            ans = i;
            break;
        }
        sum -= nums[i];
    }
    return ans;

    }
};