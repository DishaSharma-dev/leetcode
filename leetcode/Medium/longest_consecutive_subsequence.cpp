class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return 1;
        int count = 0;
        int ans = INT_MIN;
        unordered_set<int> s;
        for(int i = 0; i < nums.size(); i++) s.insert(nums[i]);
        for(int i = 0; i < nums.size(); i++){
            if(!(s.find(nums[i] - 1) != s.end())){
                int currNum = nums[i];
                count = 1;
                while(s.find(currNum + count) != s.end()){
                    count++;
                }
                ans = max(ans, count);
            }
        }
        return ans;
    }
};