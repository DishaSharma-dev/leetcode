class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int sum = nums[0];
        int ans = nums[0];
        int j = 0;
        for(int i = 1; i < nums.size(); i++){
            if(nums[j] < nums[i]){
                sum+=nums[i];
                j++;
            }
            else{
                sum = nums[i];
                j++;
            }
            if(sum > ans)
                ans = sum;
        }
        return ans;
    }
};