class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n+1, INT_MAX);
        vector<pair<int, int>> adj[n+1];
        for(int i = 0; i < times.size(); i++){
            adj[times[i][0]].push_back({times[i][1], times[i][2]});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});
        dist[k] = 0;
        while(!pq.empty()){
            int u = pq.top().second;
            pq.pop();
            for(auto it : adj[u]){
                int v = it.first;
                int cost = it.second;
                if(dist[u] != INT_MAX && dist[u] + cost < dist[v]){
                    dist[v] = dist[u] + cost;
                    pq.push({dist[v], v});
                }
            }
        }
        int ans = 0;
        for(int i = 1; i <= n; i++){
            if(dist[i] == INT_MAX) return -1;
            else ans = max(ans, dist[i]);
        }
        return ans;
    }
};