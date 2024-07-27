class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original,
                          vector<char>& changed, vector<int>& cost) {
        vector<vector<long long>> mat(26, vector<long long>(26, INT_MAX));
        
        for (int i = 0; i < original.size(); i++) {
            int s = original[i] - 'a';
            int t = changed[i] - 'a';
            mat[s][t] = min(mat[s][t], (long long)cost[i]);
        }
        for (int k = 0; k < 26; k++) {
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                        mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
                }
            }
        }

        long long ans = 0;
        for (int i = 0; i < source.length(); i++) {
            if (source[i] == target[i]) continue;

            int s = source[i] - 'a';
            int t = target[i] - 'a';

            if (mat[s][t] == INT_MAX) {
                return -1; 
            }

            ans += mat[s][t];
        }
        return ans;
    }
};