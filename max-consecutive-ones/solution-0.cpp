#include <cstdio>
#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <functional>

using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        const int n = nums.size();
        int ans = 0;
        int counter = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 1) {
                counter++;
            } else if (nums[i] == 0) {
                counter = 0;
            }
            ans = max(ans, counter);
        }
        return ans;
    }
};