class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> output;
        unordered_map<char, int> umap;
        for(auto word : words2){
            unordered_map<char, int> temp;
            for(auto it : word){
                if(umap.find(it) == umap.end()){
                    temp[it]++;
                    umap[it]++;
                }
                else if(temp[it] + 1 <= umap[it]){
                    temp[it]++;
                }
                else if(temp[it] + 1 > umap[it]){
                    temp[it]++;
                    umap[it]++;
                }
            }
        }
        unordered_map<char, int> umap2;
        for(auto word : words1){
            for(auto it : word){
                if(umap.find(it) != umap.end()){
                    umap2[it]++;
                }
            }
            bool flag = true;
            
            for(auto it : umap2){
                if(it.second < umap[it.first]){
                    flag = false;
                    break;
                }
            }
            if(flag && umap.size() == umap2.size()){
                output.push_back(word);
            }
            umap2.clear();
        }
        return output;
    }
};