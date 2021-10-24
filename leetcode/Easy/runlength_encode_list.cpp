class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> output;
        for(int i = 0; i < nums.size(); i+=2) {
            int x = nums[i];
            for(int j = 0; j < x; j++) {
                output.push_back(nums[i+1]);
            }
        }
        return output;
    }
};