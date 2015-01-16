#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <functional>


map<int, int> constructMap(vector<int>& num) {
	map<int, int> M;
	for (int i = 0; i < num.size(); ++i) {
		M[num[i]] = i;
	}
	return M;
}

using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& num, int target) {
		map<int, int> M = constructMap(num);
		int a, b;
		int indexA, indexB;
		for (int i = 0; i < num.size(); ++i) {
			a = num[i];
			b = target - a;
			if (M.count(b) != 0 && M[b] != i) {
				indexA = i + 1;
				indexB = M[b] + 1;
				break;
			}
		}
		vector<int> ans;
		ans.push_back(min(indexA, indexB));
		ans.push_back(max(indexA, indexB));
		return ans;
	}
};
