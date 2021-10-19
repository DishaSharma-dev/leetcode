class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> ans(nums.size());
        vector<int> temp(101);
        for(int i = 0; i < nums.size(); i++){
            temp[nums[i]]++;
        }
        for(int i = 1; i < 101; i++){
            temp[i]+=temp[i-1];
        }
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0) {
                ans[i] = 0;
            }
            else {
                ans[i] = temp[nums[i] - 1]; 
            }
        }
        return ans;
    }
};