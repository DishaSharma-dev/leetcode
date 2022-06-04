class Solution {
public:
    int jump(vector<int>& nums) {
        int steps = nums[0];
        int jumps = 1;
        int maxSteps = nums[0];
        int n = nums.size();
        if(n == 1) return 0;
        else if(nums[0] == 0) return -1;
        else{
            for(int i = 1; i < n; i++){
                if(i == n-1) return jumps;
                maxSteps = max(maxSteps, nums[i] + i);
                steps--;
                if(steps == 0){
                    jumps++;
                    if(i >= maxSteps) return -1;
                    steps = maxSteps - i;
                }
            }
        }
        return jumps;
    }
};