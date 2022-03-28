class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> output;
        set<pair<int, int>> store;
        for(int i = 0; i < mat.size(); i++){
            int cnt = count(mat[i].begin(), mat[i].end(), 1);
            store.insert({cnt, i});
        }
        for(auto x : store){
            if(k == 0) break;
            output.push_back(x.second);
            k--;
        }
        return output;
    }
};