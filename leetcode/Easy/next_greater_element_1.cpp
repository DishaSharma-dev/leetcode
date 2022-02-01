class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> output;
        int index;
        int flag = 0;
        unordered_map<int, int> map;
        for(int i = 0; i < nums2.size(); i++){
            map[nums2[i]] = i;
        }
        for(int i = 0; i < nums1.size(); i++){
            if(map.find(nums1[i]) != map.end()){
                index = map[nums1[i]];
                if(index+1 >= nums2.size()){
                    output.push_back(-1);
                }
                else{
                    for(int j = index + 1; j < nums2.size(); j++){
                        if(nums2[j] > nums1[i]){
                            output.push_back(nums2[j]);
                            flag = 1;
                            break;
                        }
                    }
                    if(flag == 0) output.push_back(-1);
                    flag = 0;
                }
            }
        }
        return output;
    }
};