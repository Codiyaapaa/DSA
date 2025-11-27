class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> pre(n+1);
        pre[0] = nums[0];
        for(int i=1; i<n; i++){
            pre[i] = nums[i]+pre[i-1];
        }
        // for(auto it : pre) cout<<it<<" ";
        // cout<<endl;
        long long maxi = LLONG_MIN;
        // for(int i=0; i<=n-k; i++){
        //     int j = k+i;
        //     while(j<=n){
        //         long long val = pre[j] - pre[i];
        //         maxi = max(maxi,val);
        //         j+=k;
        //     }
        // }
        // return maxi;

        for(int start = 0; start < k; start++){
            long long currSum = 0;
            int i = start;
            while(i<n && i+k-1 < n){
                int j = i+k-1;
                long long sum = pre[j] - ((i >0)?pre[i-1]:0);
                currSum = max(sum,currSum+sum);
                maxi = max(maxi,currSum);
                i += k;
            }
        }
        return maxi;
        // vector<int> arr;
        // int j=k;
        // int res = 0;
        // while(j<=n){
        //     int i = j-k;
        //     long long val = pre[j]-pre[i];
        //     arr.push_back(val);
        //     cout<<val<<" ";
        //     j++;
        // }
        // long long sum = 0;
        // long long res = INT_MIN;
        // for(int i=0; i<arr.size(); i++){
        //     // cout<<arr[i];
        //     sum+= arr[i];
        //     res = max(sum,res);
        //     if(sum < 0) sum = 0;
        // }
        // return res;
    }
};