class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int ans = INT_MAX;
        int n = words.size();
        for(int i=0; i<n; i++){
            if(words[i] == target){
                int right = abs(i - startIndex);
                int left = n - right;
                ans = min({ans,left,right});
            }
        }
        return (ans == INT_MAX)?-1:ans;
    }
};