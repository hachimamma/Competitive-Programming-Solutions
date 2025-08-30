#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int m=nums1.size();
        int n=nums2.size();
        int low=0, high=m;
        int ttlf=(m+n+1)/2;
        
        while (low <= high) {
            int partX=(low+high)/2;
            int partY=ttlf-partX;
            
            int LXmax=(partX==0) ? INT_MIN : nums1[partX - 1];
            int RXmin=(partX==m) ? INT_MAX : nums1[partX];
            
            int LYmax=(partY==0) ? INT_MIN : nums2[partY - 1];
            int RYmin=(partY==n) ? INT_MAX : nums2[partY];
            
            if (LXmax<=RYmin && LYmax<=RXmin) {
                if ((m+n)%2 == 1) {
                    return max(LXmax, LYmax);
                } else {
                    return (max(LXmax, LYmax) + min(RXmin, RYmin)) / 2.0;
                }
            } else if (LXmax>RYmin) {
                high=partX-1;
            } else {
                low=partX+1;
            }
        }
        return 0.0;
    }
};