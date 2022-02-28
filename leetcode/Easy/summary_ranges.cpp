class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int curr = 0;
        int prev = INT_MIN;
        vector<string> ans;
        string res;
        if(nums.size() == 0) return ans;
        for(int i = 0; i < nums.size(); i++){
            if(i == 0) res = to_string(nums[i]);
            else if(nums[i]-1 != nums[i-1]){
                if(prev == INT_MIN){
                    ans.push_back(res);
                    res = to_string(nums[i]);
                }
                else{
                    string str = res + "->" ;
                    str += to_string(prev);
                    ans.push_back(str);
                    res = to_string(nums[i]);
                    prev = INT_MIN;
                }
            }
            else{
                prev = nums[i];
            }
        }
        if(prev == INT_MIN){
            ans.push_back(res);
        }
        else{
            string str = res + "->" ;
            str += to_string(prev);
            ans.push_back(str);
        }
        return ans;
    }
};