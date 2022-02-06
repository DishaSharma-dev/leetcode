class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        if(nums.size() == 1 || nums.size() == 2){
            return nums;
        }
        vector<int> odd;
        vector<int> even;
        for(int i = 0; i < nums.size(); i++){
            if(i % 2 == 0) even.push_back(nums[i]);
            else odd.push_back(nums[i]);
        }
        sort(even.begin(), even.end());
        sort(odd.begin(), odd.end(), greater<int>());
        vector<int> fin;
        int count1 = 0;
        int count2 = 0;
        for(int i = 0; i < nums.size(); i++){
            if(i % 2 == 0){
                fin.push_back(even[count1]);
                count1++;
            }
            else{
                fin.push_back(odd[count2]);
                count2++;
            }
        }
        return fin;
    }
};