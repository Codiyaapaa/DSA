class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long mini = INT_MAX;
        long long maxi = INT_MIN;
        for(auto it : nums){
            if(mini > it) mini = it;
            if(maxi < it) maxi = it;
        }
        return k*(maxi-mini);
    }
};