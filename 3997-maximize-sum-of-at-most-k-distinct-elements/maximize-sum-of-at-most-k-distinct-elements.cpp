class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        sort(nums.rbegin(),nums.rend());
        int prev = INT_MAX;
        vector<int> ans;
        for(int i=0; i<nums.size(); i++){
            if(prev != nums[i]){
                ans.push_back(nums[i]);
                prev = nums[i];
                k--;
            }
            if(k == 0) break;
        }
        return ans;
    }
};