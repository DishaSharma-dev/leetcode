class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> map;
        int n = nums.size();
        for(int i = 0; i < nums.size(); i++){
            map[nums[i]]++;
            if(map[nums[i]] > n/2)
                return nums[i];
        }
        return 0;
    }
};