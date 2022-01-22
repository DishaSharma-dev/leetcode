class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans;
        unordered_map<int, int> map;
        for(int i = 0; i < nums.size(); i++){
            map[nums[i]]++;
        }
        for(int i = 0; i < nums.size(); i++){
            int check = map[nums[i]];
            if(check == 1){
                ans = nums[i];
                break;
            }
        }
        return ans;
    }
};