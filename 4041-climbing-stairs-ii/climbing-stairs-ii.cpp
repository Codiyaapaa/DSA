class Solution {
public:
    int solve(int ind, int n, vector<int>& costs, vector<int>& dp){
        if(ind > n) return INT_MAX;
        if(ind == n) return 0;

        if(dp[ind] != -1) return dp[ind];

        int one = (costs[ind] + 1 )+ solve(ind+1,n,costs,dp);
        int two = INT_MAX;
        int three = INT_MAX;

        if(ind+2 <= n) two = costs[ind+1] + 4 + solve(ind+2,n,costs,dp);
        if(ind+3 <= n) three = costs[ind+2] + 9 + solve(ind+3,n,costs,dp);

        return dp[ind] = min({one,two,three});
    }
    
    int climbStairs(int n, vector<int>& costs) {
        // vector<int> dp(n+1,-1);
        // return solve(0,n,costs,dp);

        vector<int> dp(n+1,0);
        dp[0] = 0;

        for(int i=1; i<=n; i++){
            dp[i] = INT_MAX;

            dp[i] = min(dp[i],dp[i-1] + costs[i-1]+1);
            if(i-2 >= 0) dp[i] = min(dp[i],dp[i-2] + costs[i-1] + 4);
            if(i-3 >= 0) dp[i] = min(dp[i],dp[i-3] + costs[i-1] + 9);
        }

        for(auto it : dp) cout<<it<<" ";
        return dp[n];
    }
};