class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_so_far = INT_MAX;
        int max_profit = INT_MIN;
        int profit;
        for(int i = 0; i < prices.size(); i++){
            min_so_far = min(min_so_far, prices[i]);
            profit = prices[i] - min_so_far;
            max_profit = max(max_profit, profit);
        }
        return max_profit;
    }
};