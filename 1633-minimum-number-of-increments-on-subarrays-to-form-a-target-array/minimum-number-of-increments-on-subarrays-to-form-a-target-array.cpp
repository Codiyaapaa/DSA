class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int n = target.size();
        int ans = target[0];
        int curr = ans;
        for(int i=1; i<n; i++){
            if(curr < target[i]) ans += target[i]-curr;
            curr = target[i];
        }
        return ans;
    }
};