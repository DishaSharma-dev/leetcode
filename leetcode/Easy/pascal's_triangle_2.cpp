class Solution {
public:
    int combination(int n, int r){
        long int answer = 1;
        r = min(r, n-r);
        for(int i = 0; i < r; i++){
            answer *= n;
            answer /= (i+1);
            n--;
        }
        return (int) answer;
    }
    vector<int> getRow(int rowIndex) {
        vector<int> output(rowIndex+1, 0);
        for(int i = 0; i <= rowIndex; i++){
            output[i] = combination(rowIndex, i);
        }
        return output;
    }
};