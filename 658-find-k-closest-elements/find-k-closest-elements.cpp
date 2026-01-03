class Solution {
public:
    int lower(vector<int> arr, int tar){
        int l=0;
        int r=arr.size();
        while(l<r){
            int mid = l+(r-l)/2;
            if(arr[mid]<tar) l = mid + 1;
            else r = mid;
        }
        return l;
    }

    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // method 1 : using priority_queue
        // priority_queue<pair<int,int>> pq;
        // for(int i=0; i<arr.size(); i++){
        //     pq.push({abs(arr[i]-x),arr[i]});
        //     if(pq.size() > k) pq.pop();
        // }
        // vector<int> ans;
        // while(!pq.empty()){
        //     ans.push_back(pq.top().second);
        //     pq.pop();
        // }
        // sort(ans.begin(),ans.end());
        // return ans;

        //method 2: using two pointer
        // int i=0;
        // int j=arr.size()-1;
        // // cout<<i<<" "<<j<<endl;
        // while(j-i+1 > k){
        //     if(abs(arr[i]-x) > abs(arr[j]-x)){
        //         i++;
        //     }
        //     else j--;
        // }
        // // cout<<i<<" "<<j;
        // return vector<int>(arr.begin()+i,arr.begin()+j+1);

        // method 3: binary search
        int r = lower(arr,x);
        int l = r-1;
        int n = arr.size();
        while(k--){
            if (l < 0) {
                r++;
            } 
            else if (r >= n) {
                l--;
            } 
            else if (x - arr[l] <= arr[r] - x) {
                l--;
            } 
            else {
                r++;
            }
        }
        // cout<<lb;
        return vector<int>(arr.begin()+l+1,arr.begin()+r);
    }
};