// class Solution {
// public:
//     vector<int> lexicalOrder(int n) {
//         vector<int> output;
//         int current = 1;
//         for(int i = 1; i <= n; i++){
//             output.push_back(current);
//             current *= 10; 
//             while(current > n){
//                 current /= 10;
//                 current++;
//                 while(current % 10 == 0){
//                     current /= 10;
//                 }
//             }
//         }
//         return output;
//     }
// };

class TrieNode{
    public:
    vector<TrieNode*> children;
    bool isTerminal;
    TrieNode(){
        children.resize(10, nullptr);
        isTerminal = false;
    }
};

class Solution {
    TrieNode* root;
public:
    Solution(){
        root = new TrieNode();
    }
    
    void insert(int num){
        string digit = to_string(num);
        TrieNode* itr = root;
        for(auto &ch : digit){
            if(itr->children[ch - '0'] == nullptr){
                itr->children[ch - '0'] = new TrieNode();
            }
            itr = itr->children[ch- '0'];
        }
        itr->isTerminal = true;
    }
    
    void odering(TrieNode* root, vector<int> &result, string currString){
        if(!root){
            return;
        }
        if(root->isTerminal){
            result.push_back(stoi(currString));
        }
        for(int i = 0; i < 10; i++){
            if(root->children[i]){
                odering(root->children[i], result, currString + to_string(i));
            }
        }
    }
    
    
    vector<int> lexicalOrder(int n) {
        vector<int> result;
        for(int i = 1; i <= n; i++){
            this->insert(i);
        }
        odering(root, result, "");
        return result;
    }
};