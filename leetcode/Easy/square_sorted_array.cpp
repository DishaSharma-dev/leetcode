class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
       vector<int> result(nums.size());
        int k = nums.size()-1;
        int i = 0;
        int j = nums.size()-1;
        while(i <= j){
            int val1 = nums[i] * nums[i];
            int val2 = nums[j] * nums[j];
            if(val2 > val1){
                result[k] = val2;
                j--;
            }
            else{
                result[k] = val1;
                i++;
            }
            k--;
        }
        return result;
    }
};