class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

        int n = gas.size();

        int start = 0;
        int end = 0;
        int sum = gas[start] - cost[start];
        
        while (true) {
            if (sum >= 0) {
                end = (end + 1) % n;
                sum += gas[end] - cost[end];
            } else {
                start = (start - 1) % n;
                if (start < 0) {
                    start += n;
                }
                sum += gas[start] - cost[start];
            }
            
            if (start == end) {
                break;
            }
        }

        
        if (sum < 0) {
            return -1;
        } 
        
        return start;
    }
};