#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <list>
#include <algorithm>

using namespace std;

class Solution {
public:
    int inverse(int x) { 
        int ans = 0;
        bool neg = x < 0;
        if (neg) x = -x;
        while(x) {
            ans *= 10;
            int digit = x % 10;
            x /= 10;
            ans += digit;
        }
        if (neg) ans = -ans;
        return ans;
    }
};

int main() {
    Solution* sol = new Solution();
    int v;
    while(~scanf("%d", &v)) {
        cout << sol->inverse(v) << endl;
    }
    return 0;
}
