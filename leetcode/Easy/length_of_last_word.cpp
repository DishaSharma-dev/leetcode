class Solution {
public:
    int lengthOfLastWord(string s) {
        reverse(s.begin(), s.end());
        bool ischeck = false;
        int i = 0;
        int count = 0;
        while(i < s.length()){
            if(s[i] != ' '){
                ischeck = true;
                break;
            }
            else{
                i++;
            }
        }
        while(i < s.length() && s[i] != ' '){
            count++;
            i++;
        }
        return count;
    }
};