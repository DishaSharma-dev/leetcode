class Solution {
public:
    string convertToBase7(int num) {
        string str = "";
        if(num == 0){
            return "0";
        }
        bool isNegative = false;
        if(num < 0){
            num = -num;
            isNegative = true;
        }
        while(num > 0){
            int dig = num % 7;
            num = num/7;
            str += to_string(dig);
        }
        isNegative == true ? str += '-' : str;
        reverse(str.begin(), str.end());
        return str;
    }
};