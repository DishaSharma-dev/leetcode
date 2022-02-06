class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_map<int, int> map;
        for(int i = 0; i< nums.size(); i++){
            map[nums[i]]++;
            if(map[nums[i]] > 2){
                nums.erase(nums.begin() + i); 
                i--;
            }
        }
        return nums.size();
    }
};