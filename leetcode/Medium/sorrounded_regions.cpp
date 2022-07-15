class Solution {
public:
    
    void calc(vector<vector<char>> &board, int i, int j, int n, int m){ 
        if(i < 0 || j < 0 || i >= n || j >= m || board[i][j] != 'O') return;
        board[i][j] = '$';
        calc(board, i+1, j, n, m);
        calc(board, i-1, j, n, m);
        calc(board, i, j+1, n, m);
        calc(board, i, j-1, n, m);
    }
    
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        if(n == 0) return;
        for(int i = 0; i < n; i++){
            if(board[i][0] == 'O' ) calc(board, i, 0, n, m);
            if(board[i][m-1] == 'O') calc(board, i, m-1, n, m);
        }
        for(int i = 0; i < m; i++){
            if(board[0][i] == 'O' ) calc(board, 0, i, n, m);
            if(board[n-1][i] == 'O') calc(board, n-1, i, n, m);
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == '$') board[i][j] = 'O';
                else if(board[i][j] == 'O') board[i][j] = 'X';
            }
        }
    }
};
