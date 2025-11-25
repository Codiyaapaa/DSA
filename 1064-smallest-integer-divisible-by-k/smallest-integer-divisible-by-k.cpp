class Solution {
public:
    int smallestRepunitDivByK(int k) {
        // long long limit = pow(10,k);
        int num = 1;
        // cout<<limit<<" "<<num;
        int cnt = 1;
        while(cnt<=k){
            if(num%k==0) return cnt;
            num = (num*10 + 1)%k; 
            cnt++;
            // cout<<num<<" "<<limit<<endl;
        }
        // cout<<num<<" "<<limit;
        return -1;
    }
};