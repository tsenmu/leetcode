class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> uglyNumbers(n, 0);
        uglyNumbers[0] = 1;

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, 
            greater<pair<int,pair<int,int> > > > q;
        for (int i = 0; i < primes.size(); ++i) {
            q.push(make_pair(primes[i], make_pair(1, primes[i])));
        }

        for (int i = 1; i < n; ++i) {
            uglyNumbers[i] = q.top().first;
            while (uglyNumbers[i] == q.top().first) {
                pair<int, pair<int, int>> p = q.top();
                q.pop();
                p.first = uglyNumbers[p.second.first++] * p.second.second;
                q.push(p);
            }
        }
        return uglyNumbers[n - 1];
    }
};