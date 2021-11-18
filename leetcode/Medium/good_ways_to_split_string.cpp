class Solution {
public:
    int numSplits(string s) {
        unordered_map<char,int> map1;
        unordered_map<char,int> map2;
        int count = 0;
        for(int i = 0; i < s.length(); i++){
            map1[s[i]]++;
        }
        for(int i = 0; i < s.length()-1;i++){
            map2[s[i]]++;
            map1[s[i]]--;
            if(map1[s[i]] == 0)
                map1.erase(s[i]);
            if(map1.size() == map2.size()){
                count++;
            }
        }
        return count;
    }
};