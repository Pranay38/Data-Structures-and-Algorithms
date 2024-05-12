class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size(), sum = 0;
        sum = accumulate(nums.begin(), nums.end(),0);
        int N = n/2;
        vector<vector<int>> left(N+1), right(N+1);
        for(int mask = 0; mask<(1<<N); ++mask){
            int idx = 0, l_sum = 0, r_sum = 0;
            for(int i=0; i<N; ++i){
                if(mask&(1<<i)){
                    idx++;
                    l_sum += nums[i];
                    r_sum += nums[i+N];
                }
            }
            left[idx].push_back(l_sum);
            right[idx].push_back(r_sum);
        }
        for(int idx=0; idx<=N; ++idx){
            sort(right[idx].begin(), right[idx].end());
        }
        int res = min(abs(sum-2*left[N][0]), abs(sum-2*right[N][0]));
        for(int idx=1; idx<N; ++idx){
            for(auto &a : left[idx]){
                int b = (sum - 2*a)/2;
                int rightidx = N-idx;
                auto &v = right[rightidx];
                auto itr = lower_bound(v.begin(), v.end(),b);
                if(itr!=v.end()) res = min(res, abs(sum-2*(a+(*itr))));
            }                
        }
        return res;
    }
};