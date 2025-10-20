class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int ans = 0;
        for(auto it : operations){
            // cout<<it.substr(1,1)<<endl;
            if(it.substr(1,1) == "+") ans++;
            else ans--;
        }
        return ans;
    }
};