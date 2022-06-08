class Solution {
public:
    int trap(vector<int>& height) {
        int i = 0, result = 0;
        int j = height.size() - 1;
        int leftMax = 0;
        int rightMax = 0;
        while(i <= j){
            if(height[i] <= height[j]){
                if(height[i] >= leftMax) leftMax = height[i];
                else result += (leftMax - height[i]);
                i++;
            }
            else{
                if(height[j] >= rightMax) rightMax = height[j];
                else result += (rightMax - height[j]);
                j--;
            }
        }
        return result;
    }
};