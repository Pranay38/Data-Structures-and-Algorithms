class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        unordered_map<int,int>mp;
        long long c=0;
        for(auto it:hours){
            int r=it%24;
            int q=(24-r)%24;
            if(mp.find(q)!=mp.end())
            c+=mp[q];
            mp[r]++;
        }
        return c;

    }
};