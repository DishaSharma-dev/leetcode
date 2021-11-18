class NumArray {
public:
    int dp[100001];
    NumArray(vector<int>& nums) {
        dp[0] = nums[0];
        for(int i = 1; i < nums.size(); i++){
            dp[i] = dp[i-1] + nums[i];
        }
    }
    
    int sumRange(int left, int right) {
       return (left == 0) ? dp[right] : (dp[right] - dp[left - 1]);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */