class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();
        int** dp = new int*[m+1];
        for(int i = 0; i <= m; i++){
            dp[i] = new int[n+1];
        }
        for(int  i = 0; i <= m; i++){
            dp[i][0] = 0;
        }
        for(int i = 0; i <= n; i++){
            dp[0][i] = 0;
        }
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(text1[m-i] == text2[n-j]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        int ans = dp[m][n];
        for(int i = 0; i <= m; i++){
            delete []dp[i];
        }
        delete []dp;
        return ans;
    }
};