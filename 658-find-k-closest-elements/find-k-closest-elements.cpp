class Solution {
public:
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

        //using two pointer
        int i=0;
        int j=arr.size()-1;
        // cout<<i<<" "<<j<<endl;
        while(j-i+1 > k){
            if(abs(arr[i]-x) > abs(arr[j]-x)){
                i++;
            }
            else j--;
        }
        // cout<<i<<" "<<j;
        return vector<int>(arr.begin()+i,arr.begin()+j+1);
    }
};