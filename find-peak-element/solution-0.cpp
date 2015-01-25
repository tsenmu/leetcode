class Solution {
public:
    int findPeakElement(const vector<int> &num) {
    	int const n = num.size();
    	if (n == 1) {
    		return 0;
    	}        
    	if (n > 1) {
    		if (num[0] > num[1]) { return 0; }
    		if (num[n - 1] > num[n - 2]) { return n - 1; }
    	}
        int l = 0;
        int r = n - 1;
        int m;
        while(l <= r) {
            m = (l + r) >> 1;
            if (num[m] > num[m - 1] && num[m] > num[m + 1]) {
                break;
            } else if (num[m] > num[m - 1] && num[m] < num[m + 1]) {
                l = m + 1;
            } else if (num[m] < num[m - 1] && num[m] > num[m + 1]) {
                r = m - 1;
            } else if (num[m] < num[m - 1] && num[m] < num[m + 1]) {
                l = m + 1;
            }
        }
        return m;
    }
};