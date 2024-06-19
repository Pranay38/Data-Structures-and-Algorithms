class Solution {
public:
    int characterReplacement(string s, int k) {
        //vector<int> count(26);
        unordered_map<char,int>mp;
        int mc = 0;
        
        int i = 0;
        int j = 0;
        
        int result = 0;
        
        while (j < s.size()) {
            mp[s[j] - 'A']++;
            mc = max(mc, mp[s[j] - 'A']);
            if (j - i + 1 - mc > k) {
                mp[s[i] - 'A']--;
                i++;
            }
            result = max(result, j - i + 1);
            j++;
        }
        
        return result;
    }
};