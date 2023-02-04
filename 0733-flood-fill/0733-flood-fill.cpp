class Solution {
public:
    vector<int> rowDirections = {0, 0, 1, -1};
    vector<int> columnDirections = {1, -1, 0, 0};

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        // BFS

        // queue will store the condinates of the cell (row, column)
        queue<pair<int, int>> q;

        // push the src node to the queue
        q.push({sr, sc});
        
        int orignalColor = image[sr][sc]; // 1

        // process the node (color it)
        image[sr][sc] = color; // 2

        while(!q.empty()){
            // take the front node from the queue
            pair<int, int> node = q.front();
            int currentRow = node.first;
            int currentColumn = node.second;

            // pop the node from the queue
            q.pop();

            // loop throgh the neighbours
            for(int d = 0 ; d < 4 ; d++){
                int nextRow = currentRow+rowDirections[d];
                int nextColumn = currentColumn+columnDirections[d];

                if(nextRow < 0 || nextColumn < 0 ||
                   nextRow >= image.size() || nextColumn >= image[0].size() ||
                   image[nextRow][nextColumn] == color ||
                   image[nextRow][nextColumn] != orignalColor
                    ) continue;
                
                else{
                    q.push({nextRow, nextColumn});
                    image[nextRow][nextColumn] = color;
                }
            }
        }
        return image;
    }
};

// Time complexity = O(n^2)
// Space complexity = O(L (max level nodes, because of the queue))