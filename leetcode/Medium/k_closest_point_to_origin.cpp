class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<float, int>, vector<pair<float, int>>, greater<pair<float, int>>> pq;
        for(int i = 0; i < points.size(); i++){
            int val1 = points[i][0];
            int val2 = points[i][1];
            float res = sqrt((val1*val1) + (val2*val2));
            pq.push({res, i});
        }
        vector<vector<int>> ans;
        while(k != 0){
            int out = pq.top().second;
            k--;
            pq.pop();
            ans.push_back({points[out][0], points[out][1]});
        }
        return ans;
    }
};