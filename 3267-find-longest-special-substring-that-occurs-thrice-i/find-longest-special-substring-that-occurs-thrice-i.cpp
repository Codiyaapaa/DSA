class Solution {
public:
    int maximumLength(string s) {
        int n = s.size();
        map<pair<char,int>,int> mpp;
        for(int i=0; i<n; i++){
            char ch = s[i];
            int len = 0;
            for(int j=i; j<n; j++){
                if(ch == s[j]){
                    len++;
                    mpp[{ch,len}]++;
                }
                else break;
            }
        }

        int ans = -1;
        for(auto it : mpp){
            if(it.second < 3) continue;
            ans = max(ans,it.first.second);
        }
        
        return ans;
    }
};