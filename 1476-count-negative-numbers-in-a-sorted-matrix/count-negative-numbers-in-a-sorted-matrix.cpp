class Solution {
public:
    int bs(int r, vector<int>& arr){
        int l = 0;
        while(l<r){
            int mid = l + (r-l)/2;
            if(arr[mid]<0) r = mid;
            else l = mid + 1;
        }
        return r;
    }

    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int sum = 0;
        int r = m;
        int ans = 0;
        for(int i=0; i<n; i++){
            int num = bs(r,grid[i]);
            ans = ans + (r-num)*(n-i);
            cout<<num<<" "<<r<<" ";
            r = num;
        }
        return ans;
    }
};