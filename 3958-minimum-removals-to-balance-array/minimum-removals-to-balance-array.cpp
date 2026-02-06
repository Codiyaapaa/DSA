class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        // priority_queue<int> pq;
        // priority_queue<int, vector<int>, greater<int>> pq2;
        // for (auto it : nums) {
        //     pq.push(it);
        //     pq2.push(it);
        // }

        // // while(!pq.empty()){
        // //     cout<<pq.top()<<" ";
        // //     pq.pop();
        // // }

        // //Option 1
        // auto pqMin1 = pq;
        // auto pq2Min1 = pq2;
        // int cntSmall = 0;
        // while (!pq2Min1.empty() && !pqMin1.empty() && (long long)pq2Min1.top() * k < pqMin1.top()) {
        //     pq2Min1.pop();
        //     cntSmall++;
        // }

        // // //Option 2:
        // auto pqMin2 = pq;
        // auto pq2Min2 = pq2;
        // int cntLarge = 0;
        // while (!pq2Min2.empty() && !pqMin2.empty() && (long long)pq2Min2.top() * k < pqMin2.top()) {
        //     pqMin2.pop();
        //     cntLarge++;
        // }

        // //Option 3:
        // auto pqMin3 = pq;
        // auto pq2Min3 = pq2;
        // int removeBoth = 0;
        // while (!pqMin3.empty() && !pq2Min3.empty() && (long long)pq2Min3.top() * k < pqMin3.top()) {
        //     long long minVal = pq2Min3.top();
        //     long long maxVal = pqMin3.top();
        //     if (maxVal / k > minVal) {
        //         pq2Min3.pop(); // remove smallest
        //     } else {
        //         pqMin3.pop(); // remove largest
        //     }
        //     removeBoth++;
        // }

        // return min({cntSmall, cntLarge, removeBoth});
        
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int len = 1;
        int j = 0;

        for (int i = 0; i < n; i++) {
            while (j < n && nums[j] <= (long long)nums[i] * k) {
                j++;
            }
            len = max(len, j - i);
        }

        return n - len;
    }
};
