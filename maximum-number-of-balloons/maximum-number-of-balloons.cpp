class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int> mp;
        for(char c : text) {
            mp[c]++;
        }
        
        int minCount = INT_MAX;
        string balloon = "balloon";
        for(char c : balloon) {
            int count = mp[c];
            if(c == 'l' || c == 'o') { // divide count by 2 for 'l' and 'o'
                count /= 2;
            }
            minCount = min(minCount, count);
        }
        
        return minCount;
    }
};