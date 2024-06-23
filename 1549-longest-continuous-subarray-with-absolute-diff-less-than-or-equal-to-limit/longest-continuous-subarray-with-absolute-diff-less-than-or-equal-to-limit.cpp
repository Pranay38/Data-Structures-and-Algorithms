class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> maxq;
        deque<int> minq;
        int n = nums.size();
        int i = 0;
        int ans = 0;

        for (int j = 0; j < n; j++) {
            while (!maxq.empty() && nums[j] > maxq.back())
                maxq.pop_back();
            maxq.push_back(nums[j]);

            while (!minq.empty() && nums[j] < minq.back())
                minq.pop_back();
            minq.push_back(nums[j]);

            while (!maxq.empty() && !minq.empty() && maxq.front() - minq.front() > limit) {
                if (nums[i] == maxq.front())
                    maxq.pop_front();
                if (nums[i] == minq.front())
                    minq.pop_front();
                i++;
            }

            ans = max(ans, j - i + 1);
        }

        return ans;
    }
};