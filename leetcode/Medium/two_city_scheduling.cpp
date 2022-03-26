class Solution {
public:
    static bool comparator(vector<int> &a, vector<int> &b){
        return(a[1]-a[0] > b[1]-b[0]);
    }
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int result = 0;
        sort(costs.begin(), costs.end(), comparator);
        for(int i = 0; i < costs.size(); i++){
            i >= costs.size()/2 ? result += costs[i][1] : result += costs[i][0];
        }
        return result;
    }
};