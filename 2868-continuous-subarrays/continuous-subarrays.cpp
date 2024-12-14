class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        
        int n = nums.size();
        long long count = 0;
        int left = 0;
        map<int, int> freq;

        for (int right = 0; right < n; ++right) {
            freq[nums[right]]++;

            while (freq.rbegin()->first - freq.begin()->first > 2) {
                freq[nums[left]]--;
                if (freq[nums[left]] == 0) {
                    freq.erase(nums[left]);
                }
                left++;
            }

            count += (right - left + 1);
        }

        return count;
    }
  
};