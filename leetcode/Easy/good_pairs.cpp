class Solution {
public:
    unordered_map<int,int> map;
    int good_pair = 0;
    int numIdenticalPairs(vector<int>& nums) { 
       for(int i = 0; i < nums.size(); i++) {
           map[nums[i]]++;
       }
        for(int i = 0; i < nums.size(); i++){
            if(map[nums[i]] > 1) {
                map[nums[i]]--;
                good_pair = good_pair + map[nums[i]];
            }
        }
        return good_pair;
    }
};