class Solution {
public:
    
    vector<int> compute(string &expression, int s, int e, unordered_map<string, vector<int>> &dp){
        if(dp[expression.substr(s, e - s + 1)].size()) return dp[expression.substr(s, e - s + 1)];
        vector<int> result;
        for(int i = s; i <= e; i++){
            char ch = expression[i];
            if(ch == '+' || ch == '-' || ch == '*'){
                vector<int> lvector = compute(expression, s, i-1, dp);
                vector<int> rvector = compute(expression, i+1, e, dp);
                for(auto lvalue : lvector){
                    for(auto rvalue : rvector){
                        int temp;
                        if(ch == '+') temp = lvalue + rvalue;
                        else if(ch == '-') temp = lvalue - rvalue;
                        else if(ch == '*') temp = lvalue * rvalue;
                        result.push_back(temp);
                    }
                }
            }
        }
        if(result.empty()){
            result.push_back(stoi(expression.substr(s, e - s + 1)));
        }
        return dp[expression.substr(s, e - s +1)] = result;
    }
    
    
    
    vector<int> diffWaysToCompute(string expression) {
        int n = expression.size();
        unordered_map<string, vector<int>> dp;
        return compute(expression, 0, n-1, dp);
    }
};