class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        int all = (1 << n) - 1;
        queue<tuple<int, int, int>> q;
        set<pair<int, int>> visited;
        for(int i = 0; i < n; i++){
            int mask = (1 << i);
            q.push({i, mask, 0});
            visited.insert({i, mask});
        }
        while(!q.empty()){
            auto [node, mask, cost] = q.front();
            q.pop();
            if(mask == all) return cost;
            for(auto it : graph[node]){
                int bothmask = mask | (1 << it);
                if(visited.find({it, bothmask}) == visited.end()){
                    visited.insert({it, bothmask});
                    q.push({it, bothmask, cost+1});
                }
            }
        }
        return -1;
    }
};
