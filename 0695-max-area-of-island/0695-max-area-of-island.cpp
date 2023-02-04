class Solution {
public: 
    vector<int> rowDirections = {0, 0, 1, -1};
    vector<int> columnDirections = {1, -1 , 0 , 0};

    int BFS(vector<vector<int>>& grid, int row, int col){
        queue<pair<int, int>> q;
        int area = 0;

        // push the node in the queue
        q.push({row, col});

        // Note: I will change the visited nodes to 0 value, which indicate that they are visited
        grid[row][col] = 0;
                
        // increment the area
        area += 1;

        while(!q.empty()){
            pair<int, int> node = q.front();
            int currentRow = node.first;
            int currentColumn = node.second;

            q.pop();

            for(int d = 0 ; d < 4 ; d++){
                int nextRow = currentRow + rowDirections[d];
                int nextColumn = currentColumn + columnDirections[d];

                if(nextRow < 0 || nextColumn < 0 ||
                   nextRow >= grid.size() || nextColumn >= grid[0].size() ||
                   grid[nextRow][nextColumn] == 0){
                       continue;
                }
                else{
                    q.push({nextRow, nextColumn});
                    grid[nextRow][nextColumn] = 0;
                    area += 1;
                }
            }
        }
        return area;
    }


    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;

        for(int i = 0 ; i < grid.size() ; i++){
            for(int j = 0 ; j < grid[0].size() ; j++){
                if(grid[i][j] == 1){
                    maxArea = max(maxArea, BFS(grid, i, j));
                }
            }
        }

    return maxArea;
    }
};