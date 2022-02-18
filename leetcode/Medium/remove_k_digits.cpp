class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        int n = num.length();
        for(char c : num){
            while(!st.empty() && k > 0 && st.top() > c){
                st.pop();
                k--;
            }
            if(!st.empty() || c != '0'){
                st.push(c);
            }
        }
        while(!st.empty() && k > 0){
            st.pop();
            k--;
        }
        if(st.empty()){
            return "0";
        }
        string str;
        while(!st.empty()){
            str = st.top() + str;
            st.pop();
        }
        return str;
    }
};