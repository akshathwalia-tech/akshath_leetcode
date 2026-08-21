class Solution {
public: 
    // Function to find the minimum number of intervals to remove to make all intervals non-overlapping
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // Sort intervals based on their end time (greedy strategy)
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) {
            return a[1] < b[1];
        });

        // Count of intervals to remove
        int count = 0;

        // Store end time of the last non-overlapping interval
        int prevEnd = intervals[0][1];

        // Iterate through intervals starting from the second
        for (int i = 1; i < intervals.size(); i++) {

            // If current interval starts before the last accepted interval ends
            if (intervals[i][0] < prevEnd) {
                // Overlapping interval, increase removal count
                count++;
            } else {
                // No overlap, update the end of last accepted interval
                prevEnd = intervals[i][1];
            }
        }

        // Return minimum intervals to remove
        return count;
    }
};