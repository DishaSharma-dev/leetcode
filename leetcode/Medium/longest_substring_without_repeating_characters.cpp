class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() <= 1) return s.length();
        set<char> st;
        int l = 0, r = 0;
        int ans = INT_MIN;
        while(l <= r && r < s.length()){
            char ch = s[r];
            if(st.find(ch) == st.end()){
                st.insert(ch);
                ans = max(ans, (r-l+1));
                r++;
            }
            else{
                st.erase(s[l]);
                l++;
            }
        }
        return ans;
    }
};