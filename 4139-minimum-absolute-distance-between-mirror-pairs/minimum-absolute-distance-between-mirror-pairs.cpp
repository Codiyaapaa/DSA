class Solution {
public:
    int reverse(int num){
        int val = 0;
        while(num){
            val = val*10 + num%10;
            num = num/10;
        }
        return val;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int,int> mpp;
        int n = nums.size();
        int ans = INT_MAX;
        for(int i=n-1; i>=0; i--){
            int val = reverse(nums[i]);
            if(mpp.count(val)){
                ans = min(ans,abs(mpp[val]-i));
            }
            mpp[nums[i]] = i;
        }
        return (ans==INT_MAX)?-1:ans;
    }
};