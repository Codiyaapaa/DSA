class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        int sum = 0;
        int n = nums.size();
        mpp[0] = -1;
        for(int i=0; i<n; i++){
            sum += nums[i];
            int mod = sum%k;
            if(mpp.count(mod)){
                if(i-mpp[mod] >= 2) return true;
            }
            if(mpp.find(mod) == mpp.end()) mpp[mod] = i;
        }
        return false;
    }
};