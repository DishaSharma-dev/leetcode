class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> result;
        int maximum = INT_MIN;
        for(int i = 0; i < candies.size(); i++) {
            if(maximum < candies[i])
                maximum = candies[i];
        }
        
        for(int i = 0; i < candies.size(); i++){
            if((candies[i] + extraCandies) >= maximum) {
                result.push_back(true);
            }
            else {
                result.push_back(false);
            }
        }
        return result;
    }
};