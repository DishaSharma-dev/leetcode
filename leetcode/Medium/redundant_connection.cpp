class Solution {
public:
    
    void makeset(vector<int> &parent, vector<int> &rank, int n){
        for(int i = 1; i <= n; i++){
            parent[i] = i;
            rank[i] = 0;
        }
    }
    
    int findparent(int node, vector<int> &parent){
        if(parent[node] == node) return node;
        return parent[node] = findparent(parent[node], parent);
    }
    
    void unionSet(vector<int> &parent, vector<int> &rank, int u, int v){
        u = findparent(u, parent);
        v = findparent(v, parent);
        if(rank[u] < rank[v]){
            parent[u] = v;
        }
        else if(rank[v] < rank[u]){
            parent[v] = u; 
        }
        else{
            parent[v] = u;
            rank[u]++;
        }
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n+1);
        vector<int> rank(n+1);
        makeset(parent, rank, n);
        for(int i = 0; i < n; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int par1 = findparent(u, parent);
            int par2 = findparent(v, parent);
            if(par1 == par2){
                return {u, v};
            } 
            unionSet(parent, rank, u, v);
        }
        return {};
    }
};