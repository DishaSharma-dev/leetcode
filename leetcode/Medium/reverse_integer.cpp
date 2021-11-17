class Solution {
public:
    int reverse(int x) {
        if(x >= 2147483648 || x <= -2147483648){
            return 0;
        }
        long long int count = 0;
        while(x != 0){
             long long int rem = x % 10;
             count = count * 10 + rem;
             if(count >= 2147483648 || count <= -2147483648){
                return 0;
             }
             x = x/10;
        }
        return count;
    }
};