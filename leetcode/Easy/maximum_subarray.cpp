class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int best = nums[0];
        int max_ending_here = 0;
        for(int i = 0; i < nums.size(); i++){
            max_ending_here = max_ending_here + nums[i];
            if(best < max_ending_here){
                best = max_ending_here;
            }
            if(max_ending_here < 0){
                max_ending_here = 0;
            }
        }
        return best;
    }
};