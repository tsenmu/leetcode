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
    int minMeetingRooms(vector<Interval>& intervals) {
        const int n = intervals.size();
        sort(intervals.begin(), intervals.end(), cmp);

        priority_queue<int, vector<int>, greater<int> > meetingRooms;

        for (int i = 0; i < n; ++i) {

            const Interval& current = intervals[i];

            if (meetingRooms.empty()) {
                meetingRooms.push(current.end);
            } else {
                // find the meeting room with earliest ending time.
                if (meetingRooms.top() <= current.start) {
                    meetingRooms.pop();
                }
                meetingRooms.push(current.end);
            }
        }

        return meetingRooms.size();

    }
};