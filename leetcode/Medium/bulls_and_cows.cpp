class Solution {
public:
    string getHint(string secret, string guess) {
        string output;
        unordered_map<char, int> smap;
        unordered_map<char, int> gmap;
        int j = 0;
        int cows = 0;
        int bulls = 0;
        for(int i = 0; i < secret.length(); i++){
            if(secret[i] == guess[j]){
                bulls++;
                j++;
            }
            else{
                (smap[guess[j]] > 0) ? smap[guess[j]]--, cows++ : gmap[guess[j]]++;
                (gmap[secret[i]] > 0) ? gmap[secret[i]]--, cows++ : smap[secret[i]]++;
                j++;
            }
        }
        
        output = to_string(bulls) + "A" + to_string(cows) + "B";
        return output;
    }
};