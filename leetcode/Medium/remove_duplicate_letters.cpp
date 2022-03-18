class Solution {
public:
    string removeDuplicateLetters(string s) {
        bool arr[26] = {false};
        unordered_map<char, int> umap;
        stack<char> st;
        string result;
        for(int i = 0; i < s.length(); i++){
            umap[s[i]]++;
        }
        for(int i = 0; i < s.length(); i++){
            umap[s[i]]--;
            if(arr[s[i] - 'a']) continue;
            while(!st.empty() && st.top() > s[i] && umap[st.top()] > 0){
                char ch = st.top();
                arr[ch - 'a'] = false;
                st.pop();
            }
            st.push(s[i]);
            arr[s[i] - 'a'] = true;
        }
        while(!st.empty()){
            result = st.top() + result;
            st.pop(); 
        }
        return result;
    }
};