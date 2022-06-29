class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<int> output;
        int flag = 0;
        int i = 0, j = 0;
        while(i >= 0 && i < n && j >= 0 && j < m){
            if(flag == 0){
                output.push_back(mat[i][j]);
                if(i-1 >= 0 && i-1 < n && j+1 < m){
                    i = i-1;
                    j = j+1;
                }
                else{
                    flag = 1;
                    (j+1 < m) ? (j = j + 1) : (i = i + 1);
                }
            }
            else{
                output.push_back(mat[i][j]);
                if(i+1 >= 0 && i+1 < n && j-1 >=0){
                    i = i+1;
                    j = j-1;
                }
                else{
                    flag = 0;
                    (i+1 < n) ? (i+=1) : (j+=1);
                }
            }
        }
        return output;
    }
};