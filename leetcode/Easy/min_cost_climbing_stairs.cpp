class Solution {
public:
    
    int minCost(int i, vector<int> &cost, vector<int> &dp){
        if(i >= cost.size()) return 0;
        if(dp[i] != -1) return dp[i];
        int ans = INT_MAX;
        int op1 = cost[i] + min(minCost(i+1, cost, dp), minCost(i+2, cost, dp));
        ans = min(ans, op1);
        return dp[i] = ans;
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n, -1);
        return min(minCost(0, cost, dp), minCost(1, cost, dp));
    }
};