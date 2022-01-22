class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for(int i = 0; i < words.size(); i++){
            string str = words[i];
            int j = 0;
            int k = str.length()-1;
            while(j < k){
                if(str[j] != str[k]) break;
                j++;
                k--;
            }
            if(j == k || j > k) return str;
        }
        return "";
    }
};