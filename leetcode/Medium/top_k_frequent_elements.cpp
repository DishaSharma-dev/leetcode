class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> result;
        unordered_map<int, int> umap;
        for(int i = 0; i < nums.size(); i++)
            umap[nums[i]]++;
        for(auto it : umap){
            pq.push({it.second, it.first});
            if(pq.size() > k){
                pq.pop();
            }
        }
        while(!pq.empty()){
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
};