class Solution {
public:
    static bool comp(const vector<int>& vec1, const vector<int>& vec2){
        return vec1[0] < vec2[0];
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // sort the intervals
        sort(intervals.begin(), intervals.end(), comp);

        vector<vector<int>> result;
    
        int start = intervals[0][0];
        int end = intervals[0][1];

        for(int i = 1 ; i < intervals.size() ; i++){
            // check overlapping
            if(intervals[i][0] <= end){
                start = min(intervals[i][0], start);
                end = max(intervals[i][1], end);
            }
            // non overlapping
            else{
                // push the interval to the result
                result.push_back({start, end});

                // update the start and end
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }

        // push the last interval
        result.push_back({start, end});

        return result;
    }
};

// Time complexity = O(n), where n: number of intervals
// Space complexity = O(n) because of the result array (O(1) if we don't consider the result space complexity)