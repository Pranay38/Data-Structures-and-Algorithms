class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = 0;
        int eprev = 0;
        while(numBottles > 0)
        {
            ans += numBottles;
            int empty = eprev + numBottles;
            numBottles = empty / numExchange;
            eprev = empty % numExchange;
        }
        return ans;
    }
};