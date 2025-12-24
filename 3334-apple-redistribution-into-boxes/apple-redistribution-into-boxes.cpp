class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(capacity.rbegin(),capacity.rend());
        int sum = 0;
        int cnt = 0;
        for(auto it : apple) sum+=it;
        int i=0;
        while(sum > 0){
            sum -= capacity[i++];
            cnt++;
        }
        return cnt;
    }
};