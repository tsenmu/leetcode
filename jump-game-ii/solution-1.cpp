class Solution {
public:
    int jump(vector<int>& nums) {
        int last = 0;
        int cur = 0;
        int count = 0;

        for (int i = 0; i < nums.size(); ++i) {
            if (i > last) {
                if (i > cur) {
                    return -1;
                }
                count++;
                last = cur;
            } 
            cur = max(cur, i + nums[i]);
        }
        return count;
    }
};