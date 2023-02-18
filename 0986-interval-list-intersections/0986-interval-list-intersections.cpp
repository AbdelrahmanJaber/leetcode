class Solution {
public:
    bool isTwoIntervalsOverlabbed(vector<int>& interval1, vector<int>& interval2){
        return min(interval1[1], interval2[1]) - max(interval1[0], interval2[0]) >= 0;
    }

    vector<int> intersectionBetweenTwoIntervals(vector<int>& interval1, vector<int>& interval2){
        return {max(interval1[0], interval2[0]), min(interval1[1], interval2[1])};
    }

    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        // how to traverse the pointers
        int firstListIndex = 0;
        int secondListIndex = 0;

        vector<vector<int>> intersection;

        while(firstListIndex < firstList.size() && secondListIndex < secondList.size()){
            if(isTwoIntervalsOverlabbed(firstList[firstListIndex], secondList[secondListIndex])){
                intersection.push_back(intersectionBetweenTwoIntervals(firstList[firstListIndex], secondList[secondListIndex]));
            }

            if(firstList[firstListIndex][1] < secondList[secondListIndex][1]){
                firstListIndex++;
            }   
            else{
                secondListIndex++;
            }

        }



        // return the result merged
        return intersection;
    }
};