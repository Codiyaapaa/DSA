class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2) {
        // int n = nums1.size();
        // long long ans = LONG_MAX;
        // for(int it=0; it<=n; ++it){
        //     long long cost = 1;
        //     int i =0;
        //     int j = 0;
        //     while(i<n && j<n+1){
        //         if(j == it){
        //             j++;
        //             // continue;
        //         }
        //         cost +=abs(nums1[i]-nums2[j]);
        //         i++;
        //         j++;
        //     }
        //     ans = min(ans,cost);
        // }
        // return ans;
        long long ans = 0;
        int n = nums1.size();
        for(int i=0; i<n; i++){
            ans += abs(nums1[i]-nums2[i]);
        }

        int mini = INT_MAX;
        for(int i=0; i<n; i++){
            int l = min(nums1[i],nums2[i]);
            int r = max(nums2[i],nums1[i]);

            if(nums2[n] < l) mini = min(mini,l-nums2[n]);
            else if(nums2[n] > r) mini = min(mini,nums2[n]-r);
            else{
                mini = 0;
                break;
            }
        }
        return ans+mini+1;
    }
};