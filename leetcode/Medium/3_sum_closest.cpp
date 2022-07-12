class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int i, j, k;
        i = 0;
        int t;
        int ans = 1e5 ;
        while(i < nums.size() - 2){
            j = i + 1;
            k = nums.size()-1;
            while(j < k){
                int sum = (nums[j] + nums[k] + nums[i]);
                if(abs(sum - target) < abs(ans - target)) ans = sum;
                if(sum < target) j++;
                else k--;
            }
            i++;
        }
        return ans;
    }
};


