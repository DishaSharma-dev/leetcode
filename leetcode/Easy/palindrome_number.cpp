class Solution {
    int reverse(int n){
        long int result = 0;
        while(n != 0){
            int rem = n % 10;
            result = result * 10 + rem;
            n/=10;
        }
        return result;
    }
public:
    bool isPalindrome(int x) {
        if (x < 0){
            return false;
        }
        else{
            int rev = reverse(x);
            if(rev == x){
                return true;
            }
            else{
                return false;
            }
        }
    }
};