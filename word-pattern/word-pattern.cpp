class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> mp;
        int i = 0, j = 0, m = 0;
        string str = "";
        s += ' ';  // Add a space at the end of the input string to handle the last word

        while (i < pattern.size() && j < s.size()) {
            if (s[j] != ' ') {
                str += s[j];
            } else {
                if (mp.find(pattern[i]) != mp.end()) {
                    if (mp[pattern[i]] != str) {
                        return false;
                    }
                } else {
                    for (auto it = mp.begin(); it != mp.end(); ++it) {
                        if (it->second == str) {
                            return false;
                        }
                    }
                    mp[pattern[i]] = str;
                }
                i++;
                str = "";
            }
            j++;
        }

        return i == pattern.size() && j == s.size();
    }
};
