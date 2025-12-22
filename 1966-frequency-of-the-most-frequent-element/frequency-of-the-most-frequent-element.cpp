class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        long long sum = 0;
        int n = nums.size();
        int i = 0;
        int j = 0;
        int len = 0;
        while(j<n){
            sum += nums[j];
            long long num = nums[j];
            if((j-i+1)*num - sum > k){
                sum -= nums[i];
                i++;
            }
            len = max(len,j-i+1);
            j++;
        }   
        return len;
    }
};