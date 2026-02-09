class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;
        int i = 0;
        int j = height.size()-1;
        while(i<j){
            int b = min(height[i],height[j]);
            int l = j-i;
            ans = max(ans,l*b);
            if(height[i] > height[j]){
                j--;
            }
            else i++;
        }
        return ans;
    }
};