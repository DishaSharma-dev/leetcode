class Solution {
public:
    
    void reverse(vector<int> &ans, int s, int e){
        while(s < e){
          swap(ans[s], ans[e]);
          s++;
          e--;   
        }
    }
    
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        vector<int> ans;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                ans.push_back(grid[i][j]);
            }
        }
        k = k % ans.size();
        reverse(ans, 0, ans.size() - k - 1);
        reverse(ans, ans.size() - k, ans.size() - 1);
        reverse(ans, 0, ans.size() - 1);
        int count = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                grid[i][j] = ans[count];
                count++;
            }
        }
        return grid;
    }
};