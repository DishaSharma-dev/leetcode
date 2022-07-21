class Solution {
public:
    bool canJump(vector<int>& nums) {
        int jumps = 1;
        int steps = nums[0];
        int maxSteps = nums[0];
        if(nums.size() == 1) return true;
        else if(nums[0] == 0) return false;
        else{
            for(int i = 1; i < nums.size(); i++){
                if(i == nums.size() - 1) return true;
                maxSteps = max(maxSteps, i + nums[i]);
                steps--;
                if(i >= maxSteps) return false;
                steps = maxSteps - i;
            }
        }
        return true;
    }
};