class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> mpp;
        int res = 0;
        int i=0;
        int j=0;
        int n=fruits.size();
        while(j<n){
            mpp[fruits[j]]++;
            while(mpp.size() > 2){
                mpp[fruits[i]]--;
                if(mpp[fruits[i]] == 0) mpp.erase(fruits[i]);
                i++;
            }
            res = max(res,j-i+1);
            j++;
        }
        return res;
    }
};