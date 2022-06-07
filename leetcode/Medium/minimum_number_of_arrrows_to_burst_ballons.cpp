class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.size() == 1) return 1;
        sort(points.begin(), points.end());
        int count = 1;
        vector<int> temp = points[0];
        for(int i = 1; i < points.size(); i++){
            if(temp[1] >= points[i][0]){
                temp[1] = min(temp[1], points[i][1]);
            }
            else{
                count++;
                temp = points[i];
            }
        }
        return count;
    }
};