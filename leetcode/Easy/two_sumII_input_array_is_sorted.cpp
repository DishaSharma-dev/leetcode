class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0;
        int j = numbers.size() - 1;
        while(i < j){
            int sum = numbers[i] + numbers[j];
            if(sum == target){
                break;
            }
            else if(sum > target){
                j--;
            }
            else if(sum < target){
                i++;
            }
        }
        vector<int> output;
        output.push_back(i+1);
        output.push_back(j+1);
        return output;
    }
};