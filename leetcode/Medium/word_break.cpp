class Solution {
public:
    int dp[300];
    bool wordSeg(string &s, unordered_set<string> &st, int i){
        if(i >= s.length()) return true;
        if(dp[i] != -1) return dp[i];
        string t;
        for(int index = i; index < s.length(); index++){
            t += s[index];
            if(st.find(t) != st.end()){
                if(wordSeg(s, st, index + 1))
                    return true;
            }
        }
        return dp[i] = false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st;
        memset(dp, -1, sizeof(dp));
        for(auto &x : wordDict){
            st.insert(x);
        }
        return wordSeg(s, st, 0);
    }
};