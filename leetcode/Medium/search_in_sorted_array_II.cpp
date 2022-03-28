class Solution {
public:
    
    void reverse(vector<int>& nums, int s, int e){
        while(s < e){
            swap(nums[s], nums[e]);
            s++;
            e--;
        }
    }
    
    bool search(vector<int>& nums, int target) {
        int pivot = 0;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] < nums[i-1]) pivot = i;
        }
        pivot = pivot % nums.size();
        if(pivot != 0){
            reverse(nums, 0, pivot-1);
            reverse(nums, pivot, nums.size()-1);
            reverse(nums, 0, nums.size()-1); 
        }
        int l = 0;
        int h = nums.size() - 1;
        while(l <= h){
            int mid = (l+h)/2;
            cout<<mid;
            if(nums[mid] == target) return true;
            else if(target > nums[mid]){
                l = mid + 1;
            }
            else{
                h = mid-1;
            }
        }
        return false;
    }
};