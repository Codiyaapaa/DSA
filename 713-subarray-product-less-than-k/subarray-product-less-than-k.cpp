class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<=1)return 0;
        unordered_map<int,int> mpp;
        int i=0;
        int j=0;
        int ans=0;
        int num=1;
        int n=nums.size();
        while(j<n){
            num*=nums[j];
            while(num>=k && i<n){
                num/=nums[i];
                i++;
            }
            // cout<<num<<" ";
            if(num<k) ans += (j-i+1);
            j++;
        }
        return ans;
    }
};