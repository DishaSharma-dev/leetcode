class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        while(low <= high){
            int mid = (low + high)/2;
            if(mid < high && nums[mid] > nums[mid + 1]) return nums[mid + 1];
            if(mid > low && nums[mid] < nums[mid-1]) return nums[mid];
            if(nums[high] > nums[mid]){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        if(low > high) return nums[0];
        if(low == high) return low;
        return 0;
    }
};