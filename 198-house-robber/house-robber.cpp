class Solution {
public:
    int solve(int ind, vector<int>& nums){
        if(ind >= nums.size()) return 0;
        int pick = nums[ind]+solve(ind+2,nums);
        int no_pick = solve(ind+1,nums);
        return max(no_pick,pick);
    }

    int rob(vector<int>& nums) {
        // return solve(0,nums);
        int n = nums.size();
        vector<int> dp(n+1,0);
        dp[0] = nums[0];
        for(int i=1; i<n; i++){
            int pick = nums[i];
            if(i>1) pick += dp[i-2];
            int no_pick = dp[i-1];
            dp[i] = max(pick,no_pick);
        }
        return dp[n-1];
    }
};