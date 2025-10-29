class Solution {
public:
    int smallestNumber(int n) {
        for(int i=1; i<=n; i++){
            int a = pow(2,i)-1;
            // cout<<a<<" ";
            if(a >= n) return a;
        }
        return 0;
    }
};