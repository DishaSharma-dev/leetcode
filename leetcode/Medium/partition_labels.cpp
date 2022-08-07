class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, pair<int, int>> umap;
        vector<int> output;
        for(int i = 0; i < s.length(); i++){
            if(umap.find(s[i]) == umap.end()){
                umap[s[i]] = {i, i};
            }
            else{
                umap[s[i]].second = i;
            }
        }
        int u = umap[s[0]].first;
        int v = umap[s[0]].second;
        umap.erase(s[0]);
        for(int i = 1; i < s.length(); i++){
            if(umap.find(s[i]) != umap.end()){
                if(umap[s[i]].first >= u && umap[s[i]].first <= v){
                    u = min(u, umap[s[i]].first);
                    v = max(v, umap[s[i]].second);
                }
                else{
                    output.push_back(v - u + 1);
                    u = umap[s[i]].first;
                    v = umap[s[i]].second;
                }
                umap.erase(s[i]);
            }
        }
        output.push_back(v - u + 1);
        return output;
    }
};