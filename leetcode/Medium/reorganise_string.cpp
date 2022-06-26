class Solution {
public:
    
    char maximumCount(vector<int> &arr){
        char ch;
        int count = 0;
        for(int i = 0; i < 26; i++){
            if(count < arr[i]){
                count = arr[i];
                ch = i + 'a';
            }
        }
        return ch;
    }
    
    string reorganizeString(string s) {
        int n = s.length();
        if(n == 1) return s;
        vector<int> arr(26, 0);
        for(int i = 0; i < s.length(); i++){
            arr[s[i] - 'a']++;
        }
        char ch = maximumCount(arr);
        int max_count = arr[ch - 'a'];
        if(max_count > (n + 1)/2) return "";
        string result(n, ' ');
        int index = 0;
        while(max_count){
            result[index] = ch;
            index += 2;
            max_count--;
        }
        arr[ch - 'a'] = 0;
        for(int i = 0; i < 26; i++){
            while(arr[i] > 0){
                index = (index >= n) ? 1 : index;
                result[index] = i + 'a';
                index += 2;
                arr[i]--;
            }
        }
        return result;
    }
};