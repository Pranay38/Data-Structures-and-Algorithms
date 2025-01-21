class Solution {
    #define ll long long
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        ll t_sum = accumulate(grid[0].begin(),grid[0].end(),0ll);
        ll b_sum = 0;
        ll min_sum = LONG_MAX;

        for(int pp=0;pp<n;++pp){
            t_sum -= grid[0][pp];
            min_sum = min(min_sum,max(t_sum,b_sum));
            b_sum += grid[1][pp];
        }
        return min_sum;
    }
};