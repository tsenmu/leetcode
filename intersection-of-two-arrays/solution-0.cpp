class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int p = 0;
        int q = 0;
        int lastNum = 0;
        vector<int> result;

        if (nums1.size() == 0 || nums2.size() == 0) {
            return result; 
        }

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        lastNum = min(nums1[0], nums2[0]) - 1;


        while (p < nums1.size() && q < nums2.size()) {
            if (nums1[p] == nums2[q]) {
                if (lastNum != nums1[p]) {
                    lastNum = nums1[p];
                    result.push_back(lastNum);
                } else {
                    p++;
                    q++;
                }
            } else if (nums1[p] < nums2[q]) {
                p++; 
            } else {
                q++;  
            }
        }

        return result;
    }
};