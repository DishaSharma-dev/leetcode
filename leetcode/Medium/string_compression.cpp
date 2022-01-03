class Solution {
public:
    int compress(vector<char>& chars) {
        string result = "";
        int count = 1;
        result += chars[0];
        for(int i = 1; i < chars.size(); i++){
            if(chars[i] == chars[i-1]){
                count++;
            }
            else{
                if(count > 1){
                    result = result + to_string(count);
                }
                result += chars[i];
                count = 1;
            }
        }
         if(count > 1){
            result = result + to_string(count);
         }
         for(int i = 0; i < result.size(); i++){
             chars[i] = result[i];
         }
         return result.size();
    }
};