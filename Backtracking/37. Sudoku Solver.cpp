class Solution {
public:
    vector<vector<char>> board;
    bool isValidSudoku(int row, int col, char ch) 
    {
        for (int i = 0; i < 9; i++) 
            if (board[row][i] == ch or board[i][col] == ch)
                return false;

        int start_i = row/3 * 3, start_j = col/3 * 3;
        for(int i = start_i; i < start_i + 3; i++) 
            for(int j = start_j; j < start_j + 3; j++) 
                if(board[i][j] == ch) return false;
        return true;
    }

    bool generateSudoku() 
    {
        for (int i = 0; i < 9; i++) 
        {
            for (int j = 0; j < 9; j++) 
            {
                if (board[i][j] == '.') 
                {
                    for (char ch = '1'; ch <= '9'; ch++) 
                    {
                        if (isValidSudoku(i, j, ch)) 
                        {
                            board[i][j] = ch;
                            if (generateSudoku()) return true;
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& b) 
    {
        board = b;
        generateSudoku();
        b = board;
    }
};