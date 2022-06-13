class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int left[100000];
        int right[100000];
        int n = heights.size();
        stack<int> s;
        for(int i = 0; i < heights.size(); i++){
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
        for(int i = n-1; i >= 0; i--){
            if(s.empty()){
                right[i] = n - 1;
                s.push(i);
            }
            else{
                while(!s.empty() && heights[s.top()] >= heights[i]) s.pop();
                right[i] = s.empty() ? n-1 : s.top() - 1;
                s.push(i);
            }  
        }
        int max_area = 0;
        for(int i = 0; i < n; i++){
            int area = ((right[i] - left[i])  + 1) * heights[i];
            if(area > max_area) max_area = area;
        }
        return max_area;
    }
};