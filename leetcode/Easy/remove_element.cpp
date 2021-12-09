class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        int count = 0;
        while(i < nums.size()){
            if(nums[i] == val){
                nums.erase(nums.begin() + i);
            }
            else{
                 i++; 
                 count++;
            }
        }
        return count;
    }
};