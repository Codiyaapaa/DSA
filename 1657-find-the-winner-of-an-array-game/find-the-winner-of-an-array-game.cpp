class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int curr = arr[0];
        int cnt = 0;
        for(int i=1; i<arr.size(); i++){
            if(curr < arr[i]){
                cnt = 0;
                curr = arr[i];
            }
            cnt++;
            if(cnt == k) break;
        }
        return curr;
    }
};