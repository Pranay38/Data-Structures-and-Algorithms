class Solution {
public:
    bool helper(vector<vector<char>>& board, string word, int m, int n, int ptr) {
        if (ptr == word.size()) return true;
        if(m < 0 || n < 0 || m == board.size() || n == board[m].size() || board[m][n] != word[ptr]) return false;
        
        board[m][n] = '.';
        bool up = helper(board, word, m + 1, n, ptr + 1);
        bool down = helper(board, word, m - 1, n, ptr + 1);
        bool right = helper(board, word, m, n + 1, ptr + 1);
        bool left = helper(board, word, m, n - 1, ptr + 1);
        board[m][n] = word[ptr];

        return up || down || left || right;
    }

    bool exist(vector<vector<char>>& board, string word) {
        for (int m = 0; m < board.size(); m++) {
            for (int n = 0; n < board[m].size(); n++) {
                if (board[m][n] == word[0] && helper(board, word, m, n, 0)) return true;
            }
        }

        return false;
    }
};