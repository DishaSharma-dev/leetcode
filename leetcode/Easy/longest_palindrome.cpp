class Solution {
public:
    int longestPalindrome(string s) {
        if(s.length() == 1) return 1;
        unordered_map<char, int> umap;
        for(int i = 0; i < s.length(); i++){
            umap[s[i]]++;
        }
        int count = 0;
        int odd_count = 0;
        for(auto it : umap){
            if(it.second % 2 == 0) count += it.second;
            else{
                count += (it.second - 1);
                odd_count++;
            }
        }
        if(odd_count) count++;
        return count;
    }
};