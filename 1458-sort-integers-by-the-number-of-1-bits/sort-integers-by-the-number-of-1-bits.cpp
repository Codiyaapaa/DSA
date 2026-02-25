class Solution {
public:
    static bool cmp(int a, int b){
        int temp1 = a;
        int temp2 = b;
        int cnt1 = 0;
        int cnt2 = 0;
        while(temp1){
            if(temp1%2 == 1) cnt1++;
            temp1/=2;
        }
        while(temp2){
            if(temp2%2 == 1) cnt2++;
            temp2/=2;
        }
        if(cnt1==cnt2) return (a<=b);
        else return (cnt1<cnt2);

    }

    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),cmp);
        return arr;
    }
};