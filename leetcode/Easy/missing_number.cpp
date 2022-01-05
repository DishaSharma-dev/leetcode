class Solution {
public:
    int missingNumber(vector<int>& nums) {
        unordered_map<int,int> map;
        int ans;
        int maxi = INT_MIN;
        for(int i = 0; i < nums.size(); i++){
            maxi = max(maxi, nums[i]);
            map[nums[i]]++;
        }
        for(int i = 0; i <= maxi+1; i++){
            if(map.count(i) == 0){
                ans = i;
                break;
            }
        }
        return ans;
    }
};
