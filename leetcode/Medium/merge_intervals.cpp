class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> output;
        int n = intervals.size();
        bool flag = false;
        if(intervals.size() == 1) return intervals;
        sort(intervals.begin(), intervals.end());
        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i][0] <= intervals[i-1][1]){
                if(i == n-1){
                    flag = true; 
                    intervals[i][0] = intervals[i-1][0];
                    intervals[i][1] = max(intervals[i-1][1], intervals[i][1]);
                    output.push_back(intervals[i]);
                }
                else{
                     intervals[i][0] = intervals[i-1][0];
                     intervals[i][1] = max(intervals[i-1][1], intervals[i][1]);
                }      
            }
            else{
                output.push_back(intervals[i-1]);
            }
        }
        if(!flag) output.push_back(intervals[n-1]); 
        return output;
    }
};