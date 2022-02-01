class Solution {
public:
    bool isvalid(char c){
        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
            return true;
        return false;
    }
    char to_lower(char c){
        if(c >= 'A' && c <= 'Z')
            c+=32;
        return c;
    }
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.length()-1;
        while(i < j){
            if(!isvalid(s[i])) i++;
            else if(!isvalid(s[j])) j--;
            else if(to_lower(s[i]) != to_lower(s[j])) return false;
            else{
                i++;
                j--;
            }
        }
        return true;
    }
};