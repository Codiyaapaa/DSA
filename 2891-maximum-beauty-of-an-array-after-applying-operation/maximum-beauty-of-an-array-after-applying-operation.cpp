class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        vector<pair<int,int>> pr;
        for(auto it : nums){
            int num1 = it-k;
            int num2 = it+k;
            pr.push_back({num1,num2});
        }
        queue<int> q;
        int res = 0;
        for(auto it : pr){
            
            while(!q.empty() && q.front() < it.first) {
                cout<<q.front()<<" "<<q.front()<<endl;
                q.pop();
            }
            q.push(it.second);
            int sz = q.size();
            res = max(res,sz);
        }
        return res;
    }
};