class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        unordered_set<int> minRow;
        for(int row = 0; row < matrix.size(); row++) {
            int mini = INT_MAX;
            for(int col = 0; col < matrix[row].size(); col++) {
                mini = min(mini, matrix[row][col]);
            }
            minRow.insert(mini);
        }

        unordered_set<int> maxCol;
        for(int col = 0; col < matrix[0].size(); col++) {
            int maxi = INT_MIN;
            for(int row = 0; row < matrix.size(); row++) {
                maxi = max(maxi, matrix[row][col]);
            }
            maxCol.insert(maxi);
        }

        vector<int> ans;
        for(const int &elem : minRow) {
            if(maxCol.find(elem) != maxCol.end()) {
                ans.push_back(elem);
            }
        }

        return ans;
    }
};