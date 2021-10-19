class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        int n1 = 2*n;
        vector<int> ans;
        int i;
        for(i=0;i<n1;i++){
            if(i < n)
                ans.push_back(nums[i]);
            else{
                int index = i-n;
                ans.push_back(nums[index]);
            }
        }
        
    return ans;
    }
};