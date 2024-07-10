class Solution {
public:
    bool isLower(char c) { return (c >= 'a' && c <= 'z'); }
    bool isUpper(char c) { return (c >= 'A' && c <= 'Z'); }
    string makeGood(string s) {
        string ans = "";
        int n = s.length();
        for (int i = 0; i < n; i++) {
            if (isLower(s[i])) {
                if (ans != "" && isUpper(ans.back()) && toupper(s[i])==ans.back())
                    ans.pop_back();
                else
                    ans += s[i];
            }
        else {
            if (ans != "" && isLower(ans.back()) && tolower(s[i])==ans.back())
                ans.pop_back();
            else
                ans += s[i];
        }
        }
          return ans;
    }
};