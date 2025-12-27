class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum = 0;
        int i=0;
        int j=0;
        int maxi = INT_MIN;
        int n=nums.size();
        while(j<k){
            sum+=nums[j];
            j++;
        }
        maxi = max(sum,maxi);
        while(j<n){
            sum = sum - nums[i];
            sum = sum + nums[j];
            maxi = max(sum,maxi);
            i++;
            j++;
        }
        return double(maxi)/k;
    }
};