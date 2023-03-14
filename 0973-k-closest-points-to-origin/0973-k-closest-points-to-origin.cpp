class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double, vector<int>>, vector<pair<double, vector<int>>>, greater<pair<double, vector<int>>>> pointsDestinations;

        for(int i = 0 ; i < points.size() ; i++){
            double distance = sqrt(pow(points[i][0], 2) + pow(points[i][1], 2));
            pointsDestinations.push({distance, points[i]});
        }

        vector<vector<int>> output;
        while(k--){
            pair<double, vector<int>> point = pointsDestinations.top();
            pointsDestinations.pop();

            output.push_back(point.second);
        }

        return output;
    }
};