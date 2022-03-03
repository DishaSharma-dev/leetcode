class Solution {
public:
    bool isHappy(int n) {
        set<int> s;
        while(1){
            int calc = 0;
            while(n){
                int rem = n % 10;
                calc += rem*rem;
                n /= 10;
            }
            if(calc == 1) return true;
            if(s.find(calc) != s.end()) return false;
            s.insert(calc);
            n = calc;
        }
        return false;
    }
};