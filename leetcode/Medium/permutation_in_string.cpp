class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length()){
            return false;
        }
        int size1 = s1.length();
        int size2 = s2.length();
        vector<int> s1hash(26,0);
        vector<int> s2hash(26,0);
        int left = 0;
        int right = 0;
        while(right < s1.length()){
            s1hash[s1[right] - 'a']++;
            s2hash[s2[right] - 'a']++;
            right++;
        }
        right -= 1;
        while(right < s2.length()){
            if(s1hash == s2hash) return true;
            right += 1;
            if(right < s2.length()){
                s2hash[s2[right] - 'a']++;
            }
            s2hash[s2[left] - 'a']--;
            left += 1;
        }
        return false;
    }
};
