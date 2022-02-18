class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
        long product = 0;
        bool flag = 0;
        bool track = 0;
        int count = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != 0){
                if(track == 0){
                    product = 1;
                    track = 1;
                }
                 product *= nums[i];
            }
            else{
                flag = 1;
                count++;
            }
        }
        for(int i = 0; i < nums.size(); i++){
            if(flag != 1){
                int output = product/nums[i];
                ans.push_back(output);
            }
            else{
                if(nums[i] != 0){
                    ans.push_back(0);
                }
                else{
                    if(count > 1){
                        ans.push_back(0);
                    }
                    else{
                        ans.push_back(product);
                    }
                }
            }
        }
        return ans;
    }
};