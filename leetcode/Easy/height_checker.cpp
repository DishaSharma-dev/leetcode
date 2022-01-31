class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> check(heights.size());
        for(int i = 0; i < heights.size(); i++){
            check[i] = heights[i];
        }
        int count = 0;
        sort(check.begin(), check.end());
        for(int i = 0; i < heights.size(); i++){
            if(check[i] != heights[i]) count++;
        }
        return count;
    }
};