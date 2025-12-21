class Solution {
public:
    int minSubArrayLen(int k, vector<int>& nums) {
        int len = INT_MAX;
        int i=0;
        int j=0;
        int sum = 0;
        int n = nums.size();
        while(j<n || sum >= k){
            if(sum >= k){
                len = min(len,j-i);
                sum -= nums[i];
                i++;
            }
            else if(sum > k){
                sum -= nums[i];
                i++;
            }
            else{
                sum += nums[j];
                j++;
            }
        }
        if(len == INT_MAX) return 0;
        return len;
    }
};