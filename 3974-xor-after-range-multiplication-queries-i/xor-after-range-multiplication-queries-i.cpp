class Solution {
public:
    int mod = 1e9+7;
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        for(auto it : queries){
            int l = it[0];
            int r = it[1];
            int k = it[2];
            int v = it[3];

            int idx = l;
            while(idx <= r){
                long long val = nums[idx];
                val = (val*v)%mod;
                // if(idx < m) nums[idx] = (nums[idx]*v)%mod;
                nums[idx] = val;
                idx+= k;
            }
        }
        int ans = 0;
        for(auto it : nums) ans = ans ^ it;
        return ans;
    }
};