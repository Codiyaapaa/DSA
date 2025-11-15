class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        //left
        vector<int> left;
        stack<int> st1;
        if(nums[0] != 0){ 
            st1.push(0);
            left.push_back(-1);
        }
        for(int i=1; i<n; i++){
            if(nums[i] == 0){
                st1.push(i);
                continue;
            }
            if(!st1.empty() && nums[i] > nums[st1.top()]){
                left.push_back(st1.top());
                // st1.pop();              
            }else{
                while(!st1.empty() && nums[i] <= nums[st1.top()]) st1.pop();
                if(!st1.empty()) left.push_back(st1.top());
                else left.push_back(-1);
            }
            st1.push(i);
        }
        // for(auto it : left) cout<<it<<" ";
        // cout<<endl;
        //right
        vector<int> right;
        stack<int> st;
        if(nums[n-1] != 0){ 
            st.push(n-1);
            right.push_back(-1);
        }
        for(int i=n-2; i>=0; i--){
            if(nums[i] == 0){
                st.push(i);
                continue;
            }
            if(!st.empty() && nums[i] > nums[st.top()]){
                right.push_back(st.top());
                // st.pop();
            }
            else{
                while(!st.empty() && nums[i] <= nums[st.top()]) st.pop();
                if(!st.empty()) right.push_back(st.top());
                else right.push_back(-1);
            }
            st.push(i);
        }
        reverse(right.begin(),right.end());
        // for(auto it : right) cout<<it<<" ";
        set<pair<int,int>> ans;
        for(int i=0; i<left.size(); i++){
            ans.insert({left[i],right[i]});
        }
        return ans.size();
    }
};