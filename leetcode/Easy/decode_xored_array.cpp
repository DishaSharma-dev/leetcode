class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> output(encoded.size() + 1);
        output[0] = first;
        for(int  i = 0; i < encoded.size(); i++) {
            output[i+1] = encoded[i] ^ output[i];
        }
        return output;
    }
};