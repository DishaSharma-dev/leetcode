class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int i = 0;
        int n = s.length();
        vector<int> ans(n);
        int l = 0;
        int r = 0;
        while(i < n){
            if(s[i] == c){
                l = i;
                r = i + 1;
            }
            while(r < n && s[r] != c) r++;
            while(l < n && s[l] != c) l++;
            if(r == n) r = INT_MAX;
            ans[i] = min(abs(l-i), abs(r-i));
            i++;
        }
        return ans;
    }
};

