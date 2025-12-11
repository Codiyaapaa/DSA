class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        int start = 0;
        int end = n-1;
        int ans = 0;
        sort(people.begin(),people.end());
        
        while(start <= end){
            if(people[start]+people[end] <= limit){
                cout<<people[start]<<" "<<people[end]<<endl;
                start++;
                end--;
            }
            else{
                cout<<people[end]<<endl;
                end--;
            }
            ans++;
        }
        return ans;
    }
};