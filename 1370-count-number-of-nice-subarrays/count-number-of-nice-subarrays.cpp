class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
    int i = 0, j = 0;
    int odd = 0;
    int c = 0;
    int pc = 0;

    while (j < n) {
        if (nums[j] % 2 == 1)
            odd++;

        if (odd == k)
            pc = 0;

        while (odd >= k) {
            if (nums[i] % 2 == 1)
                odd--;

            pc++;
            i++;
        }

        c += pc;

        j++;
    }

    return c;
    }
};