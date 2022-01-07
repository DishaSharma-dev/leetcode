class Solution {
    int partition(vector<int>& nums, int low, int high){
        int pivot = nums[high];
        int pindex = low;
        for(int i = low; i < high; i++){
            if(nums[i] > pivot){
                swap(nums[i], nums[pindex]);
                pindex++;
            }
        }
        swap(nums[pindex], nums[high]);
        return pindex;
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        int low = 0;
        int high = nums.size() - 1;
         while(low <= high){
            int index = partition(nums, low, high);
            if(index == k-1){
                return nums[index];
            }
            else if(index < k-1){
                low = index + 1;
            }
            else{
                high = index - 1;
            }
        }
        return -1;
    }
};