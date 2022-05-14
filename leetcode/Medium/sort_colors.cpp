class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i = 0, j = 0;
        int k = nums.size() - 1;
        while(i <= k){
            if(nums[i] == 2){
                swap(nums[i], nums[k]);
                k--;
            }
            else if(nums[i] != 1){
                swap(nums[i], nums[j]);
                i++;
                j++;
            }
            else{
                i++;
            }
        }
    }
};