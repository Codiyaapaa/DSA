class Solution {
public:
    int minSubArrayLen(int k, vector<int>& nums) {
        int len = INT_MAX;
        int i=0;
        int j=0;
        int sum = 0;
        int n = nums.size();
        while(j<n){
            sum += nums[j];
            while(sum >= k){
                len = min(len,j-i+1);
                sum -= nums[i];
                i++;
            }
            j++;
        }
        if(len == INT_MAX) return 0;
        return len;
    }
};