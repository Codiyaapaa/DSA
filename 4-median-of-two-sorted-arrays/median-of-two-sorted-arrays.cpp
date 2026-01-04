class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i=0;
        int j=0;
        int n=nums1.size();
        int m=nums2.size();
        double m1 = 0;
        double m2 = 0;
        for(int k=0; k<=(n+m)/2; k++){
            m2 = m1;
            if(i != n && j != m){
                if(nums1[i] < nums2[j]){
                    m1 = nums1[i++];
                }
                else m1 = nums2[j++];
            }
            else if(i < n){
                m1 = nums1[i++];
            }
            else m1 = nums2[j++];
        }
        if((n+m)%2) return m1;
        cout<<m1<<" "<<m2;
        return double(m1+m2)/2;
    }
};