class Solution {
public:
		Solution() {
			memset(mat, -1, sizeof mat);
		}
		int mat[105][105];
    int uniquePaths(int m, int n) {
 			if (m == 1 || n == 1) {
 				return 1;
 			}       
 			if (m > n) {
 				swap(m, n);
 			}
 			if (mat[n][m] != -1) {
 				return mat[n][m];
 			} 
 			return mat[n][m] = uniquePaths(m - 1, n) + uniquePaths(m, n - 1);
    }
};