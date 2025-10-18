class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        set<int> st;
        int n = nums.size();
        nums[0] = nums[0] - k;
        int prev = nums[0];
        st.insert(nums[0]);
        for(int i=1; i<n; i++){
            if( k == 0 ){
                st.insert(nums[i]);
                continue;
            } 
            int x = max(prev+1,nums[i]-k);
            if(x > nums[i] + k) continue;
            prev = x;
            st.insert(prev);
        }
        for(auto it : st) cout<<it<<" ";
        return st.size();
    }
};