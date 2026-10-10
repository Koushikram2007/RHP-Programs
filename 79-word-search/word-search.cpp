
class Solution {
public:
    const int d[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
    int count = 0;

    void dfs(int r, int c, int R, int C,
             vector<vector<char>>& grid, int idx, string word) {

        if (idx == word.length()) {
            count = idx;
            return;
        }

        if (r < 0 || r >= R || c < 0 || c >= C ||
            grid[r][c] != word[idx]) {
            return;
        }

        char temp = grid[r][c];
        grid[r][c] = '#';

        for (int i = 0; i < 4; i++) {
            int ar = r + d[i][0];
            int ac = c + d[i][1];

            dfs(ar, ac, R, C, grid, idx + 1, word);

            if (count == word.length()) {
                grid[r][c] = temp;
                return;
            }
        }

        grid[r][c] = temp;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int R = board.size();
        int C = board[0].size();
        int idx = 0;

        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                if (board[r][c] == word[idx]) {
                    dfs(r, c, R, C, board, idx, word);

                    if (count == word.length()) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};
