class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int, int>> adj[n];
        int m = flights.size();
        for(int i = 0; i < m; i++){
            int s = flights[i][0];
            int e = flights[i][1];
            adj[s].push_back({e, flights[i][2]});
        }
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        queue<pair<int, int>> q;
        q.push({0, src});
        k += 1;
        while(!q.empty()){
            k--;
            if(k < 0) break;
            int len = q.size();
            for(int i = 0; i < len; i++){
                int top = q.front().second;
                int wt = q.front().first;
                q.pop();
                for(auto it : adj[top]){
                    if(it.second + wt < dist[it.first]){
                        dist[it.first] = it.second + wt;
                        q.push({dist[it.first], it.first});
                    }
                }
            }
        }
        return dist[dst] == INT_MAX ? - 1 : dist[dst];
    }
};