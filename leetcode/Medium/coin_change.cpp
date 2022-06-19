class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size() + 1;
        int m = amount + 1;
        int dp[n][m];
        memset(dp, 0, sizeof(dp));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(i == 0 && j > 0){
                    dp[i][j] = INT_MAX - 1;
                }
                else if(j == 0){
                   dp[i][j] = 0; 
                }
                else if(coins[i - 1] > j){
                    dp[i][j] = dp[i-1][j];
                }
                else{
                    dp[i][j] = min(dp[i-1][j], 1 + dp[i][j - coins[i - 1]]);
                }
            }
        }
        return dp[n-1][m-1] > 1e4 ? -1 : dp[n-1][m-1];
    }
};