class Solution {
public:
    int minimumLength(string s) {
        int n = 0;
        vector<int> freq(26, 0); 

        for (char c : s) {
            freq[c - 'a']++;
        }

        for (int count : freq) {
            if (count > 0) {
                n += (count % 2 == 0) ? 2 : 1;
            }
        }

        return n;
    }
};