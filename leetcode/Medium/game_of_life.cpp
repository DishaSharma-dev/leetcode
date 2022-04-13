class Solution {
public:
    bool isSafe(int x, int y, int R, int C){
        return (x >= 0 && x < R && y >= 0 && y < C);
    }
    void gameOfLife(vector<vector<int>>& board) {
        int R = board.size();
        int C = board[0].size();
        int livecount;
        int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
        int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
        for(int i = 0; i < R; i++){
            for(int j = 0; j < C; j++){
                livecount = 0;
                for(int k = 0; k < 8; k++){
                    if(isSafe(i + dx[k], j + dy[k], R, C) && abs(board[i + dx[k]][j + dy[k]]) == 1)
                        livecount++;
                }
                if(board[i][j] == 0 && livecount == 3){
                    board[i][j] = 2;
                }
                if(board[i][j] == 1 && (livecount < 2 || livecount > 3))
                    board[i][j] = -1;
            }
        }
        for(int i = 0; i < R; i++){
            for(int j = 0; j < C; j++){
                board[i][j]  =  board[i][j] > 0 ? 1 : 0;
            }
        }
    }
};