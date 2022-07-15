class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<vector<int>> output;
        for(int i = 0; i < nums.size(); i++){
            for(int j = 0; j < nums[i].size(); j++){
                if(output.size() == i + j){
                    output.push_back(vector<int>());
                }
                output[i+j].push_back(nums[i][j]);
            }
        }
        vector<int> ans;
        for(auto x : output){
            ans.insert(ans.end(), x.rbegin(), x.rend());
        }
        return ans;
    }
};

