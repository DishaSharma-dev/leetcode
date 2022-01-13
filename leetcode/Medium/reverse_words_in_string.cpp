class Solution {
    void reverseWord(string&s , int start, int end){
        while(start < end){
            swap(s[start], s[end]);
            start++,
            end--;
        }
    }
public:
    string reverseWords(string s) {
        int index = 0;
        // remove extra spaces
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != ' ' || (s[i] == ' ' && i != 0 && s[i - 1] != ' ')) {
                s[index] = s[i];
                index++;
            }
        }
        
	    s.resize(index);
        int n = s.length();
        int j;
        for(int i = 0; i < n;){
            while(i < n && s[i] == ' '){
                s[i] = '*';
            }
            
            j = i+1;
            while(j < n && s[j] != ' '){
                j++;
            }
            reverseWord(s, i, j-1);
            i = j + 1;
            j = 0;
        }
        reverse(s.begin(), s.end());   
         if(s[0] == ' '){
            s.erase(0, 1);
        }
        return s;
    }
};