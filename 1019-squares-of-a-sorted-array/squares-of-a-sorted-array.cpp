class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int>tmep;
        for(int i=0;i<nums.size();i++){
            tmep.push_back(nums[i]*nums[i]);

        }
        sort(tmep.begin(),tmep.end());
        return tmep;
    }
};