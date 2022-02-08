class Solution {
public:
    int addDigits(int num) {
        if(num < 10){
            return num;
        }
        while(num > 9){
            int rem = num%10;
            num = num /10;
            num = num + rem;  
        }
        return num;
    }
};