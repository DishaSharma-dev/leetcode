class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> output(n*m);
        int top = 0;
        int bottom = n - 1;
        int left = 0;
        int right = m - 1;
        int k = 0;
        while(top <= bottom && left <= right){
            for(int i = left; i <= right; i++){
                output[k++] = matrix[top][i];
            }
            top++;
            for(int i = top; i <= bottom; i++){
                output[k++] = matrix[i][right];
            }
            right--;
            if(top <= bottom){
                for(int i = right; i >= left; i--){
                    output[k++] = matrix[bottom][i];
                }
                bottom--;
            }
            if(left <= right){
                for(int i = bottom; i >= top; i--){
                    output[k++] = matrix[i][left];
                }
                left++;
            }
        }
        return output;
    }
};