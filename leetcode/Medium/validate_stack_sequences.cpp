class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int j = 0, i = 0;
        stack<int> st;
        for(i = 0; i < pushed.size(); i++){
            st.push(pushed[i]);
            while(!st.empty() && st.top() == popped[j]){
                st.pop();
                j++;
            }
        }
        return st.size() == 0;
    }
};