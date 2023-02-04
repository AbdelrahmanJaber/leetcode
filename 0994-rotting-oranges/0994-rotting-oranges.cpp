class Solution {
public:
    vector<int> rowDirections = {0, 0, 1, -1};
    vector<int> columnDirections = {1, -1, 0 , 0};

    int BFS(vector<vector<int>>& grid){
        queue<pair<int, int>> q;

        for(int i = 0 ; i < grid.size() ; i++){
            for(int j = 0 ; j < grid[0].size() ; j++){
                if(grid[i][j] == 2){
                    q.push({i, j});
                }
            }
        }

        int minMinutes = 0;
        int size = q.size();

        while(!q.empty()){
            pair<int, int> node = q.front();
            int currentRow = node.first;
            int currentColumn = node.second;

            q.pop();
            size--;

            for(int d = 0 ; d < 4 ; d++){
                int nextRow = currentRow + rowDirections[d];
                int nextColumn = currentColumn + columnDirections[d];

                if(nextRow < 0 || nextColumn < 0 ||
                   nextRow >= grid.size() || nextColumn >= grid[0].size() ||
                   grid[nextRow][nextColumn] == 0 || grid[nextRow][nextColumn] == 2
                   ){
                       continue;
                   }
                   else{
                       q.push({nextRow, nextColumn});
                       grid[nextRow][nextColumn] = 2;
                   }
            }

            if(size == 0 && q.size() != 0){
                minMinutes++;
                size = q.size();
            }
        }

        return minMinutes;
    }

    bool checkRottenGrid(vector<vector<int>>& grid){
        for(int i = 0 ; i < grid.size() ; i++){
            for(int j = 0 ; j < grid[0].size() ; j++){
                if(grid[i][j] == 1) return false;
            }
        }
        return true;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int minimumMinutes = BFS(grid);

        bool isAllRotten = checkRottenGrid(grid);
        return isAllRotten?minimumMinutes:-1;
    }
};