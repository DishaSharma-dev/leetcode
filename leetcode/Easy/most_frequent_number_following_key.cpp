class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) {
        unordered_map<int, int> um;
        int maxCt = INT_MIN, output;
        for(int i = 0; i < nums.size() - 1; ++i)
        {
            if(nums[i] == key) ++um[nums[i + 1]];
        }
        
        for(auto it : um)
        {
            if(it.second > maxCt)
            {
                maxCt = it.second;
                output = it.first;
            }
                
        }
        return output;
    }
};