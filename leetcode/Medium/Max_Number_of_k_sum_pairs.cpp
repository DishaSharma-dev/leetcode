class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> umap;
        int count = 0;
        for(int i = 0; i < nums.size(); i++){
           if(umap[k - nums[i]] > 0){
               count++;
               umap[k - nums[i]]--;
           }
            else{
                umap[nums[i]]++;
            }
        }
        
        return count;
    }
};