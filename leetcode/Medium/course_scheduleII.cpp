class Solution {
public:
    
    void topo(int node, vector<int> adj[], vector<int> &flag, stack<int> &st){
        flag[node] = 1;
        for(auto it : adj[node]){
            if(!flag[it]){
                topo(it, adj, flag, st);
            }
        }
        st.push(node);
    }
    
    bool checkCycle(int node, vector<int> adj[], vector<int> &visited, vector<int> &dfs){
        visited[node] = 1;
        dfs[node] = 1;
        for(auto it : adj[node]){
            if(!visited[it]){
                if(checkCycle(it, adj, visited, dfs)) return true;
            }
            else if(dfs[it] == 1) return true;
        }
        dfs[node] = 0;
        return false;
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<int> visited(numCourses + 1, 0);
        vector<int> dfs(numCourses + 1, 0);
        vector<int> adj[numCourses + 1];
        for(int i = 0; i < prerequisites.size(); i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            adj[v].push_back(u);
        }
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                if(checkCycle(i, adj, visited, dfs)) return {};
            }
        }
        stack<int> st;
        vector<int> flag(n + 1, 0);
        for(int i = 0; i < n; i++){
            if(!flag[i]){
                topo(i, adj, flag, st);
            }
        }
        vector<int> output;
        while(!st.empty()){
            output.push_back(st.top());
            st.pop();
        }
        return output;
    }
};