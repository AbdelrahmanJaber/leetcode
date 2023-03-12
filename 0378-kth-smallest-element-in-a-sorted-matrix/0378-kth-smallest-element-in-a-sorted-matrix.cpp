class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        // think of the problem as merge k arrays, where each row in the matrix is an array, and k: is number of rows in the matrix (here = n)
        // we can use a min heap to push the elements inside it, and once we pop the K element, it will be the result

        // Time complexity = O(N * logk), where N: n1(first row) + n2 (second row) + n3(thid row) + ... = n^2
        // = O(n^2 log k)
        //Space complexity = O(k)

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> values;
        for(int i = 0; i < matrix.size() ; i++){
            values.push({matrix[i][0], {i, 0}});
        }

        int n = matrix.size();

        while(--k){
            pair<int, pair<int, int>> smallerValue = values.top();
            values.pop();

            int i = smallerValue.second.first;
            int j = smallerValue.second.second;

            if(j + 1 < n){
                values.push({matrix[i][j+1], {i, j+1}});
            }
        }   

        return values.top().first;
    }
};