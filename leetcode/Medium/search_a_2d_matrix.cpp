class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix[0].size();
        for(int i = 0; i < matrix.size(); i++){
            if(matrix[i][n-1] < target) continue;
            for(int j = 0; j < matrix[i].size(); j++){
                if(matrix[i][j] == target) return true;
            }
            return false;
        }
        return false;
    }
};