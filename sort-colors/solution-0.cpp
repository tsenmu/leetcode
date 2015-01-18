class Solution {
public:
    void sortColors(int A[], int n) {
 			int l = 0;
 			int r = n - 1;       
 			int i = 0;
 			while (l < r) {
 				if (A[l] == 0) {
 					l++;
 				} else if (A[r] == 2) {
 					r--;
 				} else if (A[l] == 2) {
 					swap(A[l], A[r]);
 				} else if (A[r] == 0) {
 					swap(A[l], A[r]);
 				} else if (i < l) {
 					i = l + 1;
 				} else if (i > r) {
 					break;
 				} else if (A[i] == 0) {
 					swap(A[l], A[i]);
 					i++;
 				} else if (A[i] == 2) {
 					swap(A[r], A[i]);
 					i++;
 				} else {
 					i++;
 				}
 			}
    }
};