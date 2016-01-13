class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start = 0;
        int gas_sum = 0;
        int cost_sum = 0;
        int tank = 0;
        int n = gas.size();

        for (int i = 0; i < n; ++i) {
            gas_sum += gas[i];
            cost_sum += cost[i];
            tank += gas[i] - cost[i];

            if (tank < 0) {
                start = i + 1;
                tank = 0;
            }
        }

        if (cost_sum > gas_sum) {
            return -1;
        }


        return start;
    }
};