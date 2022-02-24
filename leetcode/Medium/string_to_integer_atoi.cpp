class Solution {
public:
    int myAtoi(string s) {
        int sign = 1;
        int i = 0;
        long long result = 0;
        while(i < s.length() && s[i] == 32) i++;
        if(i < s.length() && s[i] == '-'){
           sign = -1;
           i++;
        } 
        else if(i < s.length() && s[i] == '+') i++;
        while(i < s.length() && (s[i] - '0') >= 0 && (s[i] - '0') <= 9){
                result = result*10 + (s[i] - '0');
                i++;
            if(result > INT_MAX || (-result) < INT_MIN){
                break;
            }
        }
        result *= sign;
        if(result > INT_MAX || result < INT_MIN){
            result = (result < 0) ? INT_MIN : INT_MAX;
        }
        return  (result);
    }
};