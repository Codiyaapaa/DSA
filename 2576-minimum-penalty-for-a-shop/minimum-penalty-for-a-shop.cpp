class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        vector<int> open(n+1);
        vector<int> close(n+1);
        for(int i=1; i<=n; i++){
            open[i] = open[i-1] + (customers[i-1]=='N'?1:0); 
        }
        for(int i=n-1; i>=0; i--){
            close[i] = close[i+1] + (customers[i]=='Y'?1:0); 
        }
        int mini = INT_MAX;
        int res = 0;
        for(int i=0; i<=n; i++){
            if(mini > open[i]+close[i]){
                res = i;
                mini = open[i]+close[i];
            }
        }
        return res;
    }
};