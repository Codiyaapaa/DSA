class Solution {
public:
    int mirrorFrequency(string s) {
        int ans = 0;
        vector<int> num(10);
        vector<int> chr(26);

        for(auto it : s){
            if(it >= '0' && it <= '9'){
                num[it-'0']++;
            }
            else{
                chr[it-'a']++;
            }
        }

        for(int i=0; i<5; i++){
            ans += abs(num[i] - num[9-i]);
        }
        for(int i=0; i<13; i++){
            ans += abs(chr[i] - chr[25-i]);
        }
        return ans;
    }
};