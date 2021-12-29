class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> output;
        int n = nums.size();
        if(n == 0){
            return output;
        }
        unordered_map<int,int> map;
        for(int i = 0; i < n; i++){
            map[nums[i]] = i;
        }
        for(int i = 0; i < n; i++){
            if(map[nums[i]] == i){
                map.erase(nums[i]);
            }
            int check = target - nums[i];
            if(map.count(check) > 0){
                output.push_back(i);
                output.push_back(map[check]);
                break;
            }
        }
         return output;
    }
};