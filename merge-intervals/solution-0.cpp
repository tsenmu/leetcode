/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

class Solution {
protected:
    static bool cmp(const Interval& a, const Interval& b) {
        if (a.start == b.start) {
            return a.end < b.end; 
        }

        return a.start < b.start;
    }
public:
    vector<Interval> merge(vector<Interval>& intervals) {

        const int n = intervals.size();

        if (n == 0 || n == 1) {
            return intervals;
        }

        vector<Interval> result;

        sort(intervals.begin(), intervals.end(), cmp);

        Interval current = intervals[0];

        for (int i = 1; i < n; ++i) {
            if (current.end < intervals[i].start) {
                result.push_back(current);
                current = intervals[i];
            } else {
                current.end = max(intervals[i].end, current.end);
            }
        }

        result.push_back(current);
        return result;
    }
};