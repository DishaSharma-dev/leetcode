class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> map;
        int sum = 0;
        int largest_sum = 0;
        int count = 0;
        for(int i = 0; i < nums.size(); i++){
            nums[i] == 1 ? sum += 1 : sum -= 1;
            if(sum == 0){
                if(largest_sum < i+1){
                    largest_sum = i+1;
                }
            }
            else if(map.find(sum) == map.end()){
                map[sum] = i;
            }
            else{
                count = i - map[sum];
            }
            if(count > largest_sum) largest_sum = count;
            count = 0;
        }
        return largest_sum;
    }
};