class Solution {
public:
	void getSearchRange(int A[], int n, int target, int& begin, int& end) {
		int l, r, m;
		l = 0;
		r = n - 1;
		while(l <= r) {
			m = (l + r) >> 1;
			if (m + 1 <= r) {
			// if m has a valid neighbour on its right
				if (A[m] > A[m+1]) {
					break;	
				} else if (A[l] < A[m]) {
					l = m + 1;
				} else if (A[r] > A[m]) {
					r = m - 1;
				}
			} else {
			// if m does not have a valid neighbour on its right,
			// r == m, l == m or l == m - 1 ,
			// we only have to assert l
				if (A[l] > A[l+1]) {
					m = l;
				}
				break;
			}
		}
		if (target <= A[n-1]) {
			begin = min(m + 1, n - 1);
			end = n - 1;
		} else {
			begin = 0;
			end = m;
		}
	}
	int binarySearch(int A[], int l, int r, int target) {
		int m;
		while(l <= r) {
			m = (l + r) >> 1;
			if (A[m] == target) {
				return m;
			} else if (A[m] > target) {
				r = m - 1;
			} else {
				l = m + 1;
			}
		}
		return -1;
	}
	int search(int A[], int n, int target) {
		int begin, end;
		getSearchRange(A, n, target, begin, end);
		return binarySearch(A, begin, end, target);
	}
};