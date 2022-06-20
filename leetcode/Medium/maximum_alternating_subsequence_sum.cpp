class Solution {
public:
    int dp[100000][2];
    long long subSum(vector<int> &nums, int i, int flag){
        if(i == nums.size()) return 0;
        if(dp[i][flag] != -1) return dp[i][flag];
        long long sum = 0;
        // include
        if(flag){
            sum = nums[i] + subSum(nums, i + 1, !flag);
        }
        //exclude
        sum = max(sum, max(- nums[i] + subSum(nums, i+1, !flag), subSum(nums, i + 1, flag)));
        dp[i][flag] = sum;
        return sum;
    }
    
    long long maxAlternatingSum(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return subSum(nums, 0, 1);
    }
};