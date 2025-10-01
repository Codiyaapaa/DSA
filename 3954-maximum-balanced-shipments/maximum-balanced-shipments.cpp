class Solution {
public:
    int maxBalancedShipments(vector<int>& weight) {
        int cnt = 0;
        int maxi = INT_MIN;
        int n = weight.size();
        for(int i=0; i<n; i++){
            maxi = max(maxi,weight[i]);
            if(maxi > weight[i]){
                maxi = INT_MIN;
                cnt++;
            }
        }
        return cnt;
    }
};