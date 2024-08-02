class Solution {
public:
    bool f(vector<int>& mat, int target) {
        int n = mat.size();
        int start = 0;
        int end = n - 1;
        while (start <= end) {
            int mid = (start + end) / 2;
            if (mat[mid] == target)
                return true;
            else if (mat[mid] < target)
                start = mid + 1;
            else
                end = mid - 1;
        }
        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        for (int i = 0; i < n; i++) {
            if (f(matrix[i], target))
                return true;
        }
        return false;
    }
};
