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
        //O(nlogm)
        // int n = grid.size();
        // int m = grid[0].size();
        // int sum = 0;
        // int r = m;
        // int ans = 0;
        // for(int i=0; i<n; i++){
        //     int num = bs(r,grid[i]);
        //     ans = ans + (r-num)*(n-i);
        //     cout<<num<<" "<<r<<" ";
        //     r = num;
        // }
        // return ans;

        // O(n+m)
        int n = grid.size();
        int m = grid[0].size();

        int row = 0;
        int col = m-1;
        int ans = 0;
        while(row<n && col>=0){
            if(grid[row][col] < 0){
                ans += (n-row);
                col--;
            }else{
                row++;
            }
        }
        return ans;
    }
};