class Solution {
public:
    
    int robber(vector<int> arr){
        int prev = arr[0];
        int prev2 = 0;
        int curr;
        for(int i = 1; i < arr.size(); i++){
            int take = arr[i];
            if(i > 1)take += prev2;
            int non_take = prev;
            curr = max(take, non_take);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int> temp1, temp2;
        for(int i = 0; i < nums.size(); i++){
            if(i != 0) temp1.push_back(nums[i]);
            if(i != n - 1) temp2.push_back(nums[i]);
        }
        return max(robber(temp1), robber(temp2));
    }
};