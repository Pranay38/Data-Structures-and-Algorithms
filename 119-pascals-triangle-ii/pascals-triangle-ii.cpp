
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res = {1};
        for (int i = 0; i < rowIndex; i++) {
            vector<int> temp;
            temp.push_back(1);
            for (int j = 1; j < res.size(); j++) {
                temp.push_back(res[j] + res[j - 1]);
            }
            temp.push_back(1);
            res = temp;
        }
        return res;
    }
};
