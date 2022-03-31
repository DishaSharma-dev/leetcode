class Solution {
    bool isPossible(vector<int>& nums, int mid, int m){
        int sum = 0;
        int sa = 1;
        for(int i = 0; i < nums.size(); i++){
           sum += nums[i];
            if(sum > mid){
                sum = nums[i];
                sa++;
            }
            if(sa > m) return 0;
        }
        return 1;
    }
public:
    int splitArray(vector<int>& nums, int m) {
        int maxi = 0;
        int sum = 0;
        int ans = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            maxi = max(maxi, nums[i]);
        }
        if(m == nums.size()){
            return maxi;
        }
        int low = maxi;
        int high = sum;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(isPossible(nums, mid, m) == true){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
};