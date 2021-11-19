class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int x,y,maxlength = INT_MIN;
        int dp[n][n];
        for(int i = n-1; i >=0; i--){
            for(int j = i; j <= n-1; j++){
                if(i == j){
                    dp[i][j] = 1;
                }
                else if(s[i] == s[j]){
                    if(j-i == 1) dp[i][j] = 1;
                    else
                        dp[i][j] = dp[i+1][j-1];
                }
                if(dp[i][j] == 1 && j-i >= maxlength){
                    maxlength = j-i;
                    x = i;
                    y = j;
                }
            }
        }
        return s.substr(x,y-x+1);
    }
};