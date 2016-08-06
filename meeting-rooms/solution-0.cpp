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
    bool canAttendMeetings(vector<Interval>& intervals) {
        const int n = intervals.size();

        if (n == 0 || n == 1) {
            return true;
        }

        sort(intervals.begin(), intervals.end(), cmp);

        Interval current = intervals[0];

        for (int i = 1; i < n; ++i) {
            if (current.end > intervals[i].start) {
                return false;
            }
            current = intervals[i];
        }

        return true;
    }
};