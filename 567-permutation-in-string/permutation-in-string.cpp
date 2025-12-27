class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        if(m<n) return false;
        vector<int> s1F(26);
        vector<int> s2F(26);
        // int i=0;
        // int j=0;
        // while(j<n){
        //     s2F[s2[j]-'a']++;
        //     j++;
        // }
        // for(auto it : s1) s1F[it-'a']++;
        // if(s2F == s1F) return true;
        // while(j<m){
        //     s2F[s2[i]-'a']--;
        //     s2F[s2[j]-'a']++;
        //     i++;
        //     if(s2F == s1F) return true;
        //     j++;
        // }
        // return false;
        for(auto it : s1){
            s1F[it-'a']++;
        }
        int i =0;
        for(int j=0; j<m; j++){
            s2F[s2[j]-'a']++;
            if(j-i+1 > n){
                s2F[s2[i]-'a']--;
                i++;
            }
            if(s1F == s2F) return true;
        }
        return false;
    }
};