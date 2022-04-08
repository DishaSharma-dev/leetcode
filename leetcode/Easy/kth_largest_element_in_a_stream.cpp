class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int v;
    KthLargest(int k, vector<int>& nums) {
        v = k;
        if(nums.size() <= k){
            for(int i = 0; i < nums.size(); i++){
                pq.push(nums[i]);
            }
        }
        else{
            sort(nums.begin(), nums.end());
            for(int i = nums.size() - 1, a = 0; a < k; a++, i--){
                pq.push(nums[i]);
            }
        }
    }
    
    int add(int val) {
        if(v > pq.size()){
            pq.push(val);
        }
        else{
            if(val > pq.top()){
                pq.pop();
                pq.push(val);
            }
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */