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
    int singleNumber(int A[], int n) {
        map<int, int> M;
        for (int i = 0; i < n; ++i) {
            int v = A[i];
            if (M.count(v) > 0) {
                M[v]++;
            } else {
                M[v] = 1;
            }
        }
        int ans = -1;
        for (std::map<int, int>::iterator it = M.begin(); it != M.end(); ++it) {
            if (it->second == 1) {
                ans = it->first; 
                break;
            }
        }
        return ans;
    }
};

using namespace std;
int main() {
     
    return 0;
}
