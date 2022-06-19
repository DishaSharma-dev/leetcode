class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> str;
        int i = 0;
        string temp = "";
        while(i < s.length()){
           if(s[i] == ' '){
               str.push_back(temp);
               temp = "";
           }
            else{
                temp += s[i];
            }
            i++;
        }
        str.push_back(temp);
        if(pattern.size() != str.size()) return false;
        unordered_map<char, string> umap;
        set<string> set1;
        for(int i = 0; i < pattern.size(); i++){
            char ch = pattern[i];
            if(umap.find(ch) != umap.end()){
                if(umap[ch] != str[i]) return false;
            } 
            else{
                if(set1.count(str[i]) > 0) return false;
                umap[ch] = str[i];
                set1.insert(str[i]);
            }
        }
        return true;
    }
};