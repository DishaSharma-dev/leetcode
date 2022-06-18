class Solution {
public:
    
    void permutations(vector<int> nums, vector<vector<int>> &output, int index){
        if(index >= nums.size()){
            output.push_back(nums);
            return;
        }
        for(int i = index; i < nums.size(); i++){
            swap(nums[i], nums[index]);
            permutations(nums, output, index + 1);
            swap(nums[i], nums[index]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        int index = 0;
        vector<vector<int>> output;
        permutations(nums, output, index);
        return output;
    }
};