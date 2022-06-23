class Solution {
public:
    
    void subsets(vector<int> &nums, int index, vector<int> &list, vector<vector<int>> &ans){
        ans.push_back(list);
        for(int i = index; i < nums.size(); i++){
            if(i != index && nums[i] == nums[i-1]) continue;
            list.push_back(nums[i]);
            subsets(nums, i + 1, list, ans);
            list.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> list;
        vector<vector<int>> ans;
        subsets(nums, 0, list, ans);
        return ans;
    }
};