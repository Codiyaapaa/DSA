class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size();
        int m = p.size();
        if(m>n) return {};
        vector<int> ans;
        vector<int> sFreq(26,0);
        vector<int> pFreq(26,0);
        int i=0;
        int j=0;
        while(j<m){
            sFreq[s[j++]-'a']++;
        }
        for(auto it : p){
            pFreq[it-'a']++;
        }
        if(sFreq==pFreq) ans.push_back(0);
        while(j<n){
            sFreq[s[i]-'a']--;
            sFreq[s[j]-'a']++;
            i++;
            if(sFreq==pFreq) ans.push_back(i);
            j++;
        }
        return ans;
    }
};