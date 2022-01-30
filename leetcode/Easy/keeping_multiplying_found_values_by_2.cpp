class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_map<int, int> map;
        int maxi = INT_MIN;
        for(int i = 0; i < nums.size(); i++){
            map[nums[i]]++;
            maxi = max(maxi, nums[i]);
        }
        if(map.find(original) != map.end()){
            int val = 2 * original;
            while(val < maxi + 1){
                if(map.find(val) != map.end()){
                    val = 2* val;
                }
                else{
                    return val;
                }
            }
            return val;
        }
        return original;
    }
};