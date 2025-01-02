class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> prefix(words.size() + 1, 0);
        auto isVowel = [](char c) { return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'; };
        for (int i = 0; i < words.size(); ++i)
            prefix[i + 1] = prefix[i] + (isVowel(words[i][0]) && isVowel(words[i].back()));
        vector<int> ans(queries.size());
        for (int i = 0; i < queries.size(); ++i)
            ans[i] = prefix[queries[i][1] + 1] - prefix[queries[i][0]];
        return ans;
    }
};