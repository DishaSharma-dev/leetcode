class Solution {
public:
    
    class comp{
      public:
        bool operator() (string &a, string &b){
            return a.length() > b.length() || (a.length() == b.length() && a > b);
        }
    };
    
    string kthLargestNumber(vector<string>& nums, int k) {
        priority_queue<string, vector<string>, comp> p;
        for(int i = 0; i < nums.size(); i++){
            p.push(nums[i]);
        }
        while(p.size() > k){
            p.pop();
        }
        return p.top();
    }
};