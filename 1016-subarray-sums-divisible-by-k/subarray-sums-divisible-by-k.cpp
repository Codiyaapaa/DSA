class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        int sum = 0;
        mpp[0] = 1;
        int ans = 0;
        for(auto it : nums){
            sum += it;
            int mod = sum%k;
            if(mod<0) mod += k;
            ans += mpp[mod];
            mpp[mod]++;
        }
        return ans;
    }
};