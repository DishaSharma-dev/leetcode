class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int s,e;
        int length = 0;
        int res = 0;
        int p = 1;
        s = 0;
        for(e = 0; e < nums.size(); e++){
            p *= nums[e];
            while(s < e && p >= k){
                p /= nums[s];
                s += 1;
            }
            if(p < k){
                length = e - s + 1;
                res += length;
            }
        }
        return res;
    }
};