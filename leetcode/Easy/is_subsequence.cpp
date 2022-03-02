class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0;
        int j = 0;
        bool flag = false;
        while(i < s.size()){
            while(j < t.size()){
                if(s[i] == t[j]){
                    flag = true;
                    j++;
                    break;
                }
                j++;
            }
            if(!flag) return false;
            flag = false;
            i++;
        }
        return true;
    }
};