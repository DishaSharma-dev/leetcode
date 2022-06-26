/** Same as binary string with no consecutive ones **/

const int m = 1e9 + 7;
class Solution {
public:
    int countHousePlacements(int n) {
        vector<long long int> zero(n);
        vector<long long int> one(n);
        zero[0] = one[0] = 1;
        for(int i = 1; i < n; i++){
            zero[i] = zero[i-1] + one[i-1];
            zero[i] %= m;
            one[i] = zero[i-1];
        }
        long long int val = zero[n-1] + one[n-1];
        val%=m;
        val = val*val;
        val%=m;
        return (int)val;
    }
};