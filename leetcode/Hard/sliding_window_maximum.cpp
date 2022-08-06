class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> output;
        priority_queue<pair<int, int>> pq;
        for(int i = 0; i < k; i++){
            pq.push({nums[i], i});
        }
        output.push_back(pq.top().first);
        for(int i = k; i < nums.size(); i++){
            pq.push({nums[i], i});
            while(!pq.empty() && pq.top().second < i - k + 1) pq.pop();
            output.push_back(pq.top().first);
        }
        return output;
    }
};