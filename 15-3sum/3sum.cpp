class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int num1 = nums[i];
            int start = i+1;
            int end = n-1;
            while(start < end){
                if(num1 + nums[start] + nums[end] == 0){
                    ans.push_back({num1,nums[start],nums[end]});
                    while(start < end && nums[start] == nums[start+1]) start++;
                    while(start < end && nums[end] == nums[end-1]) end--;
                    start++;
                    end--;
                }
                else if(num1 + nums[start] + nums[end] > 0) end--;
                else start++;
            }
        }
        return ans;
    }
};