class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> output;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == nums[nums[i] - 1]) continue;
            else{
                swap(nums[i], nums[nums[i] - 1]);
                --i;
            }
        }
        for(int i = 0; i < nums.size(); i++){
            if(i + 1 != nums[i]){
                output.push_back(i + 1);
            }
        }
        return output;
    }
};