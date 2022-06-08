class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int remNo = 0 - nums[i];
            int x = i + 1, y = nums.size() - 1;
            while(x < y){
                if(nums[x] + nums[y]  == remNo){
                    ans.push_back({nums[i], nums[x], nums[y]});
                    x++; y--;
                    while(x < y && nums[x] == nums[x-1]) x++;
                    while(x < y && nums[y] == nums[y+1]) y--;
                }
                else if(nums[x] + nums[y] < remNo){
                    x++;
                }
                else{
                    y--;
                }
            }
        }
        return ans;
    }
};