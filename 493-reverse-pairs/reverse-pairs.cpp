class Solution {
public:
    int merge(vector<int>& nums, int low, int mid, int high) {
        int c = 0;
        int j = mid + 1;
        for (int i = low; i <= mid; i++) {
            while (j <= high && nums[i] > 2LL * nums[j]) {
                j++;
            }
            c += (j - (mid + 1));
        }
        vector<int> temp;
        int l = low, r = mid + 1;
        while (l <= mid && r <= high) {
            if (nums[l] <= nums[r]) {
                temp.push_back(nums[l++]);
            } else {
                temp.push_back(nums[r++]);
            }
        }
        while (l <= mid) {
            temp.push_back(nums[l++]);
        }
        while (r <= high) {
            temp.push_back(nums[r++]);
        }
        for (int i = low; i <= high; i++) {
            nums[i] = temp[i - low];
        }
        return c;
    }

    int mergesort(vector<int>& nums, int low, int high) {
        if (low >= high) {
            return 0;
        }
        int mid = (low + high) / 2;
        int inv = mergesort(nums, low, mid);
        inv += mergesort(nums, mid + 1, high);
        inv += merge(nums, low, mid, high);
        return inv;
    }

    int reversePairs(vector<int>& nums) {
        return mergesort(nums, 0, nums.size() - 1);
    }
};
