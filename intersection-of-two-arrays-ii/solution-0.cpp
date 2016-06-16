class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int p = 0;
        int q = 0;
        vector<int> result;

        if (nums1.size() == 0 || nums2.size() == 0) {
            return result; 
        }

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());


        while (p < nums1.size() && q < nums2.size()) {
            if (nums1[p] == nums2[q]) {
                result.push_back(nums1[p]);
                p++;
                q++;
            } else if (nums1[p] < nums2[q]) {
                p++; 
            } else {
                q++;  
            }
        }

        return result;
    }
};