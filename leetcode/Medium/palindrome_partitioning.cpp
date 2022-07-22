class Solution {
public:
    
    bool check(string ans){
        int s = 0;
        int e = ans.size() - 1;
        while(s < e){
            if(ans[s] != ans[e]) return false;
            s++; e--;
        }
        return true;
    }
    
    void solve(string s, int index, vector<string> &list, vector<vector<string>> &ans){
        if(index == s.length()){
            ans.push_back(list);
            return;
        }
        for(int i = index; i < s.length(); i++){
            string a = s.substr(index, i - index + 1);
            if(check(a)){
                list.push_back(a);
                solve(s, i+1, list, ans);
                list.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<string> list;
        vector<vector<string>> ans;
        solve(s, 0, list, ans);
        return ans;
    }
};