class Solution {
public:
    int maxArea(vector<int>& height) {
        int water = 0;
        int w = 0;
        int h = 0;
        int i = 0;
        int j = height.size()-1;
        while(i < j){
            if(height[i] <= height[j]){
                w = j-i;
                h = height[i];
                i++;
            }
            else{
                w = j - i;
                h = height[j];
                j--;
            }
            if(water < (w*h)){
                water = w*h;
            }
        }
        return water;
    }
};