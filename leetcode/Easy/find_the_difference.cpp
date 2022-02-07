class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> map;
        char c;
        for(int i = 0; i < s.length(); i++){
            map[s[i]]++;
        }
        for(int i = 0; i < t.length(); i++){
            if(map.find(t[i]) == map.end()){
                c = t[i];
                break;
            }
            map[t[i]]--;
            if(map[t[i]] == 0){
                map.erase(t[i]);
            }
        }
        return c;
    }
};