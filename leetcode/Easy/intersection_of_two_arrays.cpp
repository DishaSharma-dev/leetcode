class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> output;
        set<int> s;
        set<int> s2;
        for(int i = 0; i < nums1.size(); i++){
            s.insert(nums1[i]);
        }
        for(int i = 0; i < nums2.size(); i++){
            s2.insert(nums2[i]);
        }
        for(auto x = s2.begin(); x != s2.end(); x++){
            int val = *x;
            if(s.find(val) != s.end())
                output.push_back(val);
        }
        return output;
    }
};