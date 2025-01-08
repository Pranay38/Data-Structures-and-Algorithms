class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int count = 0;
        for (int i = 0; i < words.size(); i++) {
            for (int j = i + 1; j < words.size(); j++) {
                if (isPrefixAndSuffix(words[i], words[j])) {
                    count++;
                }
            }
        }
        return count;
    }

private:
    bool isPrefixAndSuffix(const string& str1, const string& str2) {
        int n = str1.size();
        if (n > str2.size()) {
            return false;
        }
        
        for (int i = 0; i < n; i++) {
            if (str1[i] != str2[i]) {
                return false;
            }
        }
        
        for (int i = 0; i < n; i++) {
            if (str1[i] != str2[str2.size() - n + i]) {
                return false;
            }
        }
        
        return true;
    }
};
