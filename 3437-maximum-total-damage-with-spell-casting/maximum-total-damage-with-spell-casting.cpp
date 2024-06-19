class Solution {
#define ll long long 
private:
    ll f(vector<ll>& dp, map<int, int>& frequencyMap, vector<int>& uniquePowers, int index) {
        if (index == uniquePowers.size()) return 0;
        if (dp[index] != -1) return dp[index];
       
        ll skip = f(dp, frequencyMap, uniquePowers, index + 1);
        
        ll take = 0;
        int nextIndex = index + 1;
        while (nextIndex < uniquePowers.size() && uniquePowers[nextIndex] - uniquePowers[index] <= 2) {
            nextIndex++;
        }
        take = ((1ll)*frequencyMap[uniquePowers[index]] * uniquePowers[index]) + f(dp, frequencyMap, uniquePowers, nextIndex);
        return dp[index] = max(take, skip);
    }
public:
    long long maximumTotalDamage(vector<int>& power) {
        map<int, int> frequencyMap;
        vector<int> uniquePowers;
        for (auto p : power) {
            frequencyMap[p]++;
        }
        for (auto it : frequencyMap) {
            uniquePowers.push_back(it.first);
        }
        vector<ll> dp(frequencyMap.size(), -1);
       
        return f(dp, frequencyMap, uniquePowers, 0);
    }
};