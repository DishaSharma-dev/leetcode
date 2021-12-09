class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> output;
        output.push_back(nums[0]);
        for(int i = 1; i < nums.size(); i++){
            if(output.back() < nums[i]){
                output.push_back(nums[i]);
            }
            else{
                int index = lower_bound(output.begin(),output.end(),nums[i]) - output.begin();
                output[index] = nums[i];
            }
        }
        return output.size();
    }
};