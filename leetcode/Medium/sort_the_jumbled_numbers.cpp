class Solution {
public:
    static bool sortbysec(pair<int,int> &a, pair<int,int> &b)
    {
    return (a.second < b.second);
    }
    
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        unordered_map<int, int> umap;
        vector<int> output;
        vector<pair<int, int>> tempOutput;
        
        for(int i= 0; i < mapping.size(); i++){
            umap[i] = mapping[i]; 
        }
        
        for(int i = 0; i < nums.size(); i++){
            string n = to_string(nums[i]), res = "";
            for(int j = 0; j < n.length(); j++){
                res = res + to_string(umap[(n[j] - '0')]);
            }
            int number = stoi(res);
            tempOutput.push_back(make_pair(nums[i], number));
        }
        sort(tempOutput.begin(), tempOutput.end(), sortbysec);
        
        for(int i = 0; i < tempOutput.size(); ++i)
        {
            output.push_back(tempOutput[i].first); 
        }
        return output;
    }
};