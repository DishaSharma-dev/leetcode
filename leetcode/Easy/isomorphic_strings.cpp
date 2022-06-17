class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length() != t.length()) return false;
        int visited[50000] = {0};
        unordered_map<char, char> umap;
        for(int i = 0; i < s.length(); i++){
            if(!umap[s[i]]){
                if(visited[t[i]] == 0){
                    umap[s[i]] = t[i];
                    visited[t[i]] = 1;
                }
                else return false;
            }
            else if(umap[s[i]] != t[i]) return false;
        }
        return true;
    }
};