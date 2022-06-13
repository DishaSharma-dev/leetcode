class Solution {
public:
    
    void combinations(vector<vector<int>> &output, vector<int> &pairs, int n, int k, int start){
        if(k == 0){
            output.push_back(pairs);
            return;
        }
        else{
            for(int i = start; i <= n; i++){
            pairs.push_back(i);
            combinations(output, pairs, n, k - 1, i + 1);
            pairs.pop_back();
            }
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<int> pairs;
        vector<vector<int>> output;
        combinations(output, pairs, n, k, 1);
        return output;
    }
};