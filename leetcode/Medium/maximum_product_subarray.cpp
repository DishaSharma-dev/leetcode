class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = nums[0];
        int maximum = ans;
        int minimum = ans;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] < 0){
                swap(maximum, minimum);
            }
            maximum = max(nums[i], maximum * nums[i]);
            minimum = min(nums[i], minimum * nums[i]);
            ans = max(ans, maximum);
        }
        return ans;
    }
};