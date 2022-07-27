class Solution {
public:
    
    void dfs(vector<vector<int>> &image, int m, int n, int val, int i, int j, int color){
        if(i < 0 || i >= m || j < 0 || j >= n || image[i][j] == color || image[i][j] != val){
            return;
        }
        image[i][j] = color;
        dfs(image, m, n, val, i+1, j, color);
        dfs(image, m, n, val, i-1, j, color);
        dfs(image, m, n, val, i, j+1, color);
        dfs(image, m, n, val, i, j-1, color);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        int val = image[sr][sc];
        dfs(image, m, n, val, sr, sc, color);
        return image;
    }
};