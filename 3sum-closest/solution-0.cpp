class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

        int i = 0;
        int j = 0;
        int k = 0;
        int sum = 0;
        int n = nums.size();
        long long ans = 0;

        if (n <= 3) {
            return accumulate(nums.begin(), nums.end(), 0);
        }

        sort(nums.begin(), nums.end());
        
        ans = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < n - 2; ++i) {
            j = i + 1;
            k = n - 1;
            while (j < k) { 
                sum = nums[i] + nums[j] + nums[k];
                if (abs(target - sum) < abs(target - ans)) {
                    ans = sum;
                } 

                if (sum > target) {
                    k--;
                } else if (sum < target) {
                    j++; 
                } else {
                    return (int) ans;
                }
            }
        }
        return (int) ans;
    }
};