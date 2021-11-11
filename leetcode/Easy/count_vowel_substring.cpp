class Solution {
private: 
    bool isVowel(char ch){
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
            return true;
        }
        return false;
    }
public:
    int countVowelSubstrings(string word) {
        int count = 0;
        unordered_map<char , int> map(0);
        int n = word.length();
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                if(!isVowel(word[j]))
                    break;
                if(map.count(word[j]) < 1){
                    map[word[j]] = 1;
                }
                if(map.size() == 5){
                    count++;
                }
            }
            map.clear();
        }
        return count;
    }
};