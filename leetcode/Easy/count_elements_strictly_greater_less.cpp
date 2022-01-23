class Solution {
public:
    int countElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_map<int, int> map;
        for(int i = 0; i < nums.size(); i++){
            map[nums[i]]++;
        }
        vector<int>::iterator ip;
        ip = std::unique(nums.begin(), nums.begin() + nums.size());
        nums.resize(std::distance(nums.begin(), ip));
        int count = 0;
        for(int i = 1; i < nums.size()-1; i++){
            if((nums[i-1] < nums[i] && nums[i+1] > nums[i])){
                count += map[nums[i]];
            }
        }
        return count;
    }
};