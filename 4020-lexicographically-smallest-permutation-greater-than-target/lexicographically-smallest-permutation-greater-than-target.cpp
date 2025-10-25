class Solution {
public:
    string mini;
    void solve(int ind, string s, string& target, vector<int> freq){
        int n = target.size();
        if(ind == n){
            if(s > target) mini = min(mini,s);
            return;
        }

        if(freq[target[ind]-'a'] > 0){
            freq[target[ind]-'a']--;
            solve(ind+1,s+target[ind],target,freq);
            freq[target[ind]-'a']++;
        }
            //find the next element in order
            for(int j = target[ind]-'a'+1; j<26; j++){
                if(freq[j] > 0){
                    s += 'a'+j;
                    freq[j]--;
                    for(int k=0; k<26; k++){
                        while(freq[k] > 0){
                            s += 'a' + k;
                            freq[k]--;
                        }
                    }
                    mini = min(mini,s);
                    return;
                }
            }
    }

    string lexGreaterPermutation(string s, string target) {
        vector<int> freq(26,0);
        sort(s.rbegin(), s.rend());
        mini = s;
        if(s <= target) return "";
        for(auto ch : s) freq[ch - 'a']++;
        solve(0,"",target,freq);
        return mini;
    }
};