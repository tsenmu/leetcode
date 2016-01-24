class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        const int n = coins.size();
        int dp[amount + 1];
        
        
        for (int i = 1; i <= amount; ++i) {
            dp[i] = -1;
        }
        dp[0] = 0;
        


        for (int i = 0; i <= amount; ++i) {
            for (int j = 0; j < n; ++j) {
                int val = coins[j] + i;
                if (val <= amount && dp[i] != -1) {
                    if (dp[val] == -1) {
                        dp[val] = dp[i] + 1;
                    } else {
                        dp[val] = min(dp[val], dp[i] + 1);
                    }
                }
            }
            // for (int k = 0; k <= amount; ++k) {
            //     printf("%d ", dp[k]);
            // }
            // printf("\n");
        }

        return dp[amount];
    }
};