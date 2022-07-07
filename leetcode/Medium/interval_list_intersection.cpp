class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        if(!firstList.size() || !secondList.size()) return {};
        int n = firstList.size();
        int m = secondList.size();
        int i = 0, j = 0;
        vector<vector<int>> ans;
        while(i < n && j < m){
            int val1 = max(firstList[i][0], secondList[j][0]);
            int val2 = min(firstList[i][1], secondList[j][1]);
            if(val1 >= firstList[i][0] && val1 <= firstList[i][1] && val1 >= secondList[j][0] && val1 <= secondList[j][1]&& val2 <= firstList[i][1] && val2 >= firstList[i][0] && val2 >= secondList[j][0] && val2 <= secondList[j][1]){
                ans.push_back({val1, val2});
            }
             if(firstList[i][1] < secondList[j][1]) i++;
             else j++;                                                             
        }
         return ans;                                                                  
    }
};