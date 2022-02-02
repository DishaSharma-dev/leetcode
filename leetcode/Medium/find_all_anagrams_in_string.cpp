class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int left = 0;
        int right = 0;
        vector<int> map1(26,0);
        vector<int> map2(26,0);
        vector<int> ans;
        int window = s.length();
        int length = p.length();
        if(window < length){
            return ans;
        }
        while(right < length){
            map1[p[right] - 'a']++;
            map2[s[right] - 'a']++;
            right++;
        }
        right -=1;
        while(right < window){
            if(map1 == map2){
                ans.push_back(left);
            }
            right += 1;
            if(right != window){
                map2[s[right] - 'a']++;
            }
            map2[s[left] - 'a']--;
            left += 1;
        }
        return ans;
    }
};