class Solution {
public:
    int nthUglyNumber(int n) {
        int dp[n+1];
        int p2 = 1;
        int p3 = 1;
        int p5 = 1;
        dp[1] = 1;
        for(int i = 2; i <= n; i++){
            int option1 = 2 * dp[p2];
            int option2 = 3 * dp[p3];
            int option3 = 5 * dp[p5];
            dp[i] = min(option1, min(option2, option3));
            if(dp[i] == option1){
                p2++;
            }
            if(dp[i] == option2){
                p3++;
            }
            if(dp[i] == option3){
                p5++;
            }
        }
        return dp[n];
    }
};