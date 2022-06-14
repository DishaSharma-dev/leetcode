class Solution {
public:
    
    bool checker(vector<vector<char>>& board, vector<vector<bool>> &visited, string word, int i, int j, int n, int m, int index){
        if(board[i][j] == word[index]){
            if(index == word.length() - 1){
                return true;
            }
            visited[i][j] = true;
            if(j -1 >= 0 && visited[i][j - 1] == false && checker(board, visited, word, i, j - 1, n, m, index + 1))
                return true;
            else if(j + 1 < m && visited[i][j + 1] == false && checker(board, visited, word, i, j + 1, n, m, index + 1))
                return true;
            else if(i -1 >= 0 && visited[i - 1][j] == false && checker(board, visited, word, i - 1, j, n, m, index + 1))
                return true;
            else if(i + 1 < n && visited[i  + 1][j] == false && checker(board, visited, word, i + 1, j, n, m, index + 1))
                return true;
        }
        visited[i][j] = false;
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
       int n = board.size();
        int m = board[0].size();
        vector<vector<bool>> visited(n, vector<bool> (m, false));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(checker(board, visited, word, i, j, n, m, 0)){
                    return true;
                }
            }
        }
        return false;
    }
};