class Solution {
public:
    
    int solve(int i, int j, int n, int m, vector<vector<int>>& matrix, vector<vector<int>> &dp){
        if(i < 0 || j < 0 || i >= n || j >= m) return 0;
        if(dp[i][j] != 0) return dp[i][j];
        int curr_max = 0;
        if(i+1 >= 0 && i+1 < n && matrix[i+1][j] > matrix[i][j]){
            curr_max = max(curr_max, 1 + solve(i+1, j, n, m, matrix, dp));
        }
        if(j+1 >= 0 && j+1 < m && matrix[i][j+1] > matrix[i][j]){
            curr_max = max(curr_max, 1 + solve(i, j+1, n, m, matrix, dp));
        }
        if(i-1 >= 0 && i-1 < n && matrix[i-1][j] > matrix[i][j]){
            curr_max = max(curr_max, 1 + solve(i-1, j, n, m, matrix, dp));
        }
        if(j-1 >= 0 && j-1 < m && matrix[i][j-1] > matrix[i][j]){
            curr_max = max(curr_max, 1 + solve(i, j-1, n, m, matrix, dp));
        }
        return dp[i][j] = curr_max;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        int curr_max = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                curr_max = max(curr_max, 1 + solve(i, j, n, m, matrix, dp));
            }
        }
        return curr_max;
    }
};