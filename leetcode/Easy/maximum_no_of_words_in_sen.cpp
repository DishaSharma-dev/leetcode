class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int count = 0;
        int maxi = INT_MIN;
        string str = "";
        for(int i = 0; i < sentences.size(); i++){
            str = sentences[i];
            for(int j = 0; j < str.length(); j++){
                if(str[j] == ' '){
                    count++;
                }
            }
            if(maxi < count) maxi = count;
            count = 0;
        }
        return maxi+1;
    }
};