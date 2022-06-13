class Solution {
public:
    
    int maxRectangle(int heights[], int m){
        stack<int> s;
        int left[200];
        int right[200];
        for(int i = 0; i < m; i++){
            if(s.empty()){
                left[i] = 0;
                s.push(i);
            }
            else{
                while(!s.empty() && heights[s.top()] >= heights[i]) s.pop();
                left[i] = s.empty() ? 0 : s.top() + 1;
                s.push(i);
            }
        }
        while(!s.empty()) s.pop();
        for(int i = m-1; i >= 0; i--){
            if(s.empty()){
                right[i] = m-1;
                s.push(i);
            }
            else{
                while(!s.empty() && heights[s.top()] >= heights[i]) s.pop();
                right[i] = s.empty() ? m-1 : s.top() - 1;
                s.push(i);
            }
        }
        int area = 0;
        for(int i = 0; i < m; i++){
            if(area < ((right[i] - left[i] + 1)* heights[i]))
                area = (right[i] - left[i] + 1)* heights[i];
        }
        return area;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size() == 0) return 0;
        int n = matrix.size();
        int m = matrix[0].size();
        int arr[200] = {0};
        int curr = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == '1'){
                    arr[j] += 1;
                }
                else arr[j] = 0;
            }
            curr = max(curr, maxRectangle(arr, m));
        }
        return curr;
    }
};