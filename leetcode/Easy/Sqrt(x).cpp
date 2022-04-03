class Solution {
public:
    int mySqrt(int x) {
       long long s = 0, e = x, mid;
        int ans;
        while(s <= e){
            mid = (s+e)/2;
            if(mid * mid == x) return mid;
            if(mid*mid < x){
                s = mid + 1;
                ans = mid;
            }
            else{
                e = mid - 1;
            }
        }
        return ans;
    }
};