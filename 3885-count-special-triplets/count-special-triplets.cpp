class Solution {
public:
    int mod = 1e9+7;

    int specialTriplets(vector<int>& nums) {
        unordered_map<long long,long long> left;
        unordered_map<long long,long long> right;

        for(auto it : nums) right[it]++;
        long long ans = 0;
        for(int i=0; i<nums.size(); i++){
            right[nums[i]]--;
            long long l = left[2*nums[i]];
            long long r = right[2*nums[i]];
            // cout<<l<<" "<<r<<endl;
            ans = (ans+ l*r)%mod;
            left[nums[i]]++;
        }
        return ans;
    }
};