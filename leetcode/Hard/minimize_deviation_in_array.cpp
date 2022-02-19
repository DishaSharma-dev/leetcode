class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int n = nums.size();
        set<int> s;
        for(int i = 0; i < n; i++){
            if((nums[i] & 1) != 0){
                s.insert(nums[i] * 2);
            }
            else{
                s.insert(nums[i]);
            }
        }
        int min_deviation = INT_MAX;
        while(true){
            int deviation = (*(s.rbegin())) - (*(s.begin()));
            min_deviation = min(min_deviation, deviation);
            
            int max_ele = *s.rbegin();
            if((max_ele & 1) == 0){
                s.erase(max_ele);
                s.insert(max_ele / 2);
            }
            else{
                break;
            }
        }
        return min_deviation;
    }
};