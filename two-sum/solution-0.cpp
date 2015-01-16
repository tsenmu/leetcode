class P {
public:
	int index;
	int value;	
	P(int i, int v) {
		index = i;
		value = v;
	}
};

bool cmp(P& left, P& right) {
	return left.value < right.value;
}

vector<P> organizeData(vector<int>& numbers) {
	vector<P> ret;
	for (int i = 0; i < numbers.size(); ++i) {
		P p(i, numbers[i]);
		ret.push_back(p);
	}
	return ret;	
};

class Solution {
public:

	vector<int> twoSum(vector<int>& num, int target) {
		vector<P> numbers = organizeData(num);
		sort(numbers.begin(), numbers.end(), cmp);
		int l = 0;
		int r = numbers.size() - 1;
		while(true) {
			int lv = numbers[l].value;
			int rv = numbers[r].value;
			int sum = lv + rv;
			if (sum < target) {
				l++;
			} else if (sum > target) {
				r--;
			} else {
				break;
			}
		}
		vector<int> result;
		int index0 = min(numbers[l].index, numbers[r].index) + 1;
		int index1 = max(numbers[l].index, numbers[r].index) + 1;
		result.push_back(index0);
		result.push_back(index1);

		return result;
	}
};


