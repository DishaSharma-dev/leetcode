class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size();
        for(int i = 0; i < n; i++){
            if(i == n-2 && bits[i]) return false;
            if(bits[i]) i++;
        }
        return true;
    }
};