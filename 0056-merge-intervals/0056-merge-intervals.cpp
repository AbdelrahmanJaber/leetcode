class Solution {
public:
    bool isTwoIntervalsOverlap(vector<int>& interval1, vector<int>& interval2){
        return min(interval1[1], interval2[1]) - max(interval1[0], interval2[0]) >= 0;
    }

    vector<int> mergeIntervals(vector<int>& interval1, vector<int>& interval2){
        return {min(interval1[0], interval2[0]), max(interval1[1], interval2[1])};
    }

    static bool comp(const vector<int>& vec1, const vector<int>& vec2){
        return vec1[0] < vec2[0];
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // don't forget to sort the intervals
        sort(intervals.begin(), intervals.end(), comp);

        vector<vector<int>> result;

        vector<int> currentInterval;
        for(int i = 0 ; i < intervals.size() ; i++){
            currentInterval = {intervals[i][0], intervals[i][1]};

            while(i < intervals.size() && isTwoIntervalsOverlap(currentInterval, intervals[i])){
                currentInterval = mergeIntervals(currentInterval, intervals[i]);
                i++;
            }

            i--;
            result.push_back(currentInterval);
        }

        return result;
    }
};

// Time complexity = O(n)
// Space complexity = O(1) iif we ignore the result space

// NOTE: solve this question in the start, end way (easier)
// But the functions and the way here is too useful