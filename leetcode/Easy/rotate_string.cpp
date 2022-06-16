class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length() != goal.length()) return false;
        string temp = s + s;
        int n = temp.length();
        int k = goal.length();
        int j = 0;
        for(;j < k; j++){
            if(temp[j] != goal[j])
                break;
        }
        if(j == k) return true;
        int i = j + 1;
        j = 0;
        while(i < n - k  + 1){
            if(temp[i] != goal[j]) i++;
            else{
                while(j < k && temp[i] == goal[j]){
                    i++;
                    j++;
                }
                if(j == k) return true;
                else if(i >= n - k + 1 ) break;
                else{
                    j = 0;
                }
            }
        }
        
        return false;
    }
};