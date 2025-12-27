class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;
        // for(int i=0; i<nums.size(); i++){
        //     if(!dq.empty() && dq.front() <= i-k){
        //         dq.pop_front();
        //     }
        //     while(!dq.empty() && nums[dq.back()] <= nums[i]) dq.pop_back();
        //     dq.push_back(i);
        //     if(i >= k-1) ans.push_back(nums[dq.front()]);
        // }
        // return ans;
        int i=0;
        int j=0;
        int n=nums.size();
        while(j<k){
            while(!dq.empty() && nums[dq.back()] <= nums[j]) dq.pop_back();
            dq.push_back(j);
            j++;
        }
        ans.push_back(nums[dq.front()]);
        while(j<n){
            if(dq.front() == i) dq.pop_front();
            i++;
            while(!dq.empty() && nums[dq.back()] <= nums[j]) dq.pop_back();
            dq.push_back(j);
            ans.push_back(nums[dq.front()]);
            j++;
        }
        return ans;
    }
};