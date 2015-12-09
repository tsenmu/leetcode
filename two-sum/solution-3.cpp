class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> M;      

        vector<int> result; 

        for (int i = 0; i < nums.size(); ++i) {
            int the_other = target - nums[i];

            if (M.count(the_other) != 0) {
                result.push_back(i + 1);
                result.push_back(M[the_other]);
                sort(result.begin(), result.end());
                break;
            }

            M[nums[i]] = i + 1;
        }
        return result;
    }
};