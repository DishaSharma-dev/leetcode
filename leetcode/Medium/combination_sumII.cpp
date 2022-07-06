class Solution {
public:
    
    void combinations(int index, vector<int> &candidates, vector<vector<int>> &ans, vector<int> &list, int target){
        if(target < 0 ) return;
        if(target == 0){
            ans.push_back(list);
            return;
        }
        for(int i = index; i < candidates.size(); i++){
            if(i > index && candidates[i] == candidates[i-1]) continue;
            list.push_back(candidates[i]);
            combinations(i + 1, candidates, ans, list, target - candidates[i]);
            list.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> list;
        sort(candidates.begin(), candidates.end());
        combinations(0, candidates, ans, list, target);
        return ans;
    }
};