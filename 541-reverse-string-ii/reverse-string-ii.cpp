class Solution {
public:
    string reverse(string& s, int l, int r){
        int n = s.size()-1;
        r = min(r,n);
        while(l<r){
            swap(s[l++],s[r--]);
        }
        return s;
    }

    string reverseStr(string s, int k) {
        int n = s.size();
        int l = 0;
        int r = k-1;
        // if(k >= n) return reverse(s,l,n-1);
        while(l < n){
            s = reverse(s,l,r);
            l = l + 2*k;
            r = r + 2*k;
        }
        return s;
    }
};