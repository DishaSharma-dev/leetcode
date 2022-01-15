class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int size = digits.size()-1;
        bool isbool = false;
        while(size >= 0){
            digits[size]++;
            if(digits[size] >=1 && digits[size] <= 9){
                break;
            }
            else{            
                digits[size] = 0;
                size--;
                if(size == -1){
                    isbool = true;
                }
                continue;
            }
        }
        if(isbool){
            digits.insert(digits.begin() + 0, 1);
        }
        return digits;
    }
};