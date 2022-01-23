class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        
        
        vector<int> output;
        unordered_map<int, int> um;
        
        for(int i = 0; i < nums.size(); ++i)
        {
            ++um[nums[i]];
        }
        
        for(int i = 0; i < nums.size(); ++i)
        {
            if(
                um.find(nums[i] - 1) == um.end() &&  
                um.find(nums[i] + 1) == um.end() && 
                um[nums[i]] == 1
            ) 
                    output.push_back(nums[i]);
        }
        
        return output;
    }
};