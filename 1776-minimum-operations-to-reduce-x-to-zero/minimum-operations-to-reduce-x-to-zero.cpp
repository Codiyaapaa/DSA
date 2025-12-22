class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = 0;
        int n=nums.size();
        for(auto it : nums) sum+=it;
        if(sum == x) return n;
        if(sum < x) return -1;
        sum -=x;
        int i=0;
        int j=0;
        int len = 0;
        int tar = 0;
        while(j<n){
            tar+=nums[j];
            while(tar>sum){
                tar-=nums[i];
                i++;
            }
            if(tar == sum) len = max(len,j-i+1);
            j++;
        }
        if(len == 0) return -1;
        return n-len;
    }
};