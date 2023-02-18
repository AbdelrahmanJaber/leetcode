class Solution {
public:
    bool isTwoIntervalsOverlabbed(vector<int>& interval1, vector<int>& interval2){
        return min(interval1[1], interval2[1]) - max(interval1[0], interval2[0]) >= 0;
    }

    vector<int> mergeTwoIntervals(vector<int>& interval1, vector<int>& interval2){
        return {min(interval1[0], interval2[0]), max(interval1[1], interval2[1])};
    }

    vector<vector<int>> mergeIntervals(vector<vector<int>>& intervals){
        vector<vector<int>> result;

        vector<int> currentInterval;
        for(int i = 0 ; i < intervals.size() ; i++){
            currentInterval = {intervals[i][0], intervals[i][1]};

            while(i < intervals.size() && isTwoIntervalsOverlabbed(currentInterval, intervals[i])){
                currentInterval = mergeTwoIntervals(currentInterval, intervals[i]);
                i++;
            }

            i--;
            result.push_back(currentInterval);
        }

        return result;
    }

    void insertIntervalInAscendingOrder(vector<vector<int>>& intervals, vector<int>& newInterval){
        bool newIntervalAdded = false;

        // insert the new interval to the list of intervals while keeping the order in ascending order
        // linear search until I find the first start interval which is greater than new Interval start
        for(int i = 0 ; i < intervals.size() ; i++){
            if(intervals[i][0] > newInterval[0]){
                // update the flag
                newIntervalAdded = true;

                // insert the new interval in the current position and shift the remaining intervals
                intervals.insert(intervals.begin() + i, newInterval);
                break;
            }
        }

        if(!newIntervalAdded){
            intervals.push_back(newInterval);
        }
    }

    static bool comp(const vector<int>& vec1, const vector<int>& vec2){
        return vec1[0] < vec2[0];
    }

    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        insertIntervalInAscendingOrder(intervals, newInterval);

        return mergeIntervals(intervals);
    }
};

// Time complexity = O(n), where n: number of intervals 
// (due to: 1-linear search O(n) //  2-insert and shift O(n) //  3- mergeIntervals O(n) )

// Space complexity = O(1) if we ignore the result space (if we don't O(n))