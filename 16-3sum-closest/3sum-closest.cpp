class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int diff = INT_MAX;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int ans = 0;
        for(int i=0; i<n; i++){
            int start = i + 1;
            int end = n -1;
            while(start < end){
                int sum = nums[i]+nums[start]+nums[end];
                if(abs(sum-target) < diff){
                    ans = sum;
                    diff = abs(sum-target);
                }
                else if(sum == target) return sum;
                else if(sum > target) end--;
                else start++;
            }
        }
        return ans;
    }
};