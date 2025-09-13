class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char,int> mpp;
        for(auto it : s) mpp[it]++;
        int vowels = 0;
        int consonant = 0;

        for(auto it : mpp){
            if(it.first == 'a' || it.first == 'e' || it.first == 'i' || it.first == 'o' || it.first == 'u'){
                vowels = max(vowels,it.second);
            }
            else consonant = max(consonant,it.second);
        }

        return (vowels+consonant);
    }
};