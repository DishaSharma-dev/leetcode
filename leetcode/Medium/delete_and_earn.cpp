class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int dp[10001] = {0};
        int ex = 0;
        int in = 0;
        for(int i = 0; i < nums.size(); i++){
            dp[nums[i]]++;
        }
        for(int i = 0; i <= 10000; i++){
            int ni = ex + i * dp[i];
            int ne = max(in, ex);
            
            ex = ne;
            in = ni;
        }
        return max(ex, in);
    }
};