class Solution {
public:
    int ans = INT_MIN;
    void countIsland(int i, int j, int n, int m, vector<vector<int>> &grid, vector<vector<int>> &visited, int &count){
        visited[i][j] = 0;
        if(i+1 >= 0 && i+1 < n && j >= 0 && j < m && grid[i+1][j] == 1 && visited[i+1][j] == -1){
            count += 1;
            countIsland(i + 1, j, n, m, grid, visited, count);
        }
        if(i-1 >= 0 && i-1 < n && j >= 0 && j < m && grid[i-1][j] == 1 && visited[i-1][j] == -1){
            count += 1;
            countIsland(i-1, j, n, m, grid, visited, count);
        }
        if(i >= 0 && i < n && j-1 >= 0 && j-1 < m && grid[i][j-1] == 1 && visited[i][j-1] == -1){
            count += 1;
            countIsland(i, j-1, n, m, grid, visited, count);
        }
        if(i >= 0 && i < n && j+1 >= 0 && j+1 < m && grid[i][j+1] == 1 && visited[i][j+1] == -1){
            count += 1;
            countIsland(i, j+1, n, m, grid, visited, count);
        }
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        vector<vector<int>> visited(n, vector<int>(m, -1)); 
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(visited[i][j] == -1 && grid[i][j] == 1){
                    count = 1;
                    countIsland(i, j, n, m, grid, visited, count);
                } 
                ans = max(ans, count);
            }
        }
        return ans;
    }
};