class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int moves = 0;
        for(int i=1; i<nums.size(); i++) {
            if(nums[i] <= nums[i-1]) {
                int diff = nums[i-1] - nums[i] + 1;
                moves += diff;
                nums[i] += diff;
            }
        }
        return moves;
    }
};