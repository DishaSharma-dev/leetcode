
class TrieNode{
    public:
        vector<TrieNode*> children;
        bool isTerminal;
        TrieNode(){
            children.resize(26, NULL);
            isTerminal = false;
        }
};

class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node = root;
        for(int i = 0; i < word.size(); i++){
            int index = word[i] - 'a';
            if(!node->children[index]) node->children[index] = new TrieNode();
            node = node->children[index];
        }
        node->isTerminal = true;
    }
    
    bool search(string word) {
        TrieNode* node = root;
        for(int i = 0; i < word.size(); i++){
            int index = word[i] - 'a';
            if(!node->children[index]) return false;
            node = node->children[index];
        }
        return node->isTerminal;
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for(int i = 0; i < prefix.size(); i++){
            int index = prefix[i] - 'a';
            if(!node->children[index]) return false;
            node = node->children[index];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */