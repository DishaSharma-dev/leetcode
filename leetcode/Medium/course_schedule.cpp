class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if(prerequisites.size() == 0) return true;
        vector<int> adj[numCourses];
        for(int i = 0; i < prerequisites.size(); i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<int> indegree(numCourses, 0);
        queue<int> q;
        int count = 0;
        for(int i = 0; i < numCourses; i++){
            for(auto it : adj[i]){
                indegree[it]++;
            }
        }
        for(int i = 0; i < indegree.size(); i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int temp = q.front();
            count++;
            q.pop();
            for(auto it : adj[temp]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }
        cout<<count;
        if(count == numCourses) return true;
        return false;
    }
};