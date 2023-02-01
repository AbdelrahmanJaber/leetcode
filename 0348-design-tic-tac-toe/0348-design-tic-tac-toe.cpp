class TicTacToe {
public:
    // initialize the hash maps 
    unordered_map<int, pair<int, int>> rows;
    unordered_map<int, pair<int, int>> columns;
    pair<int, int> diagonal;
    pair<int, int> reverseDiagonal;
    int n;

    TicTacToe(int n) {
        this->n = n;
        for(int i = 0 ; i< n ; i++){
            rows[i] = {0, 0};
            columns[i] = {0, 0};
        }
        diagonal = {0, 0};
        reverseDiagonal = {0, 0}; 
    }
    
    int move(int row, int col, int player) {
      if(row < 0 ||  row >= n || col < 0 ||  col >= n ){
        return 0;
      }

      // check the player
      bool flag;
      if(player == 1){
        flag = true;
      }
      else{
        flag = false;
      }
    
    // update the value
    if(flag){
      rows[row].first++;
      if(rows[row].first == n) return 1;

      columns[col].first++;
      if(columns[col].first == n) return 1;

      if(row == col){
        diagonal.first++;
        if(diagonal.first == n) return 1;
      }
      if(row + col == n-1){
        reverseDiagonal.first++;
        if(reverseDiagonal.first == n) return 1;
      }
                  
    }
else{
      rows[row].second++;
      if(rows[row].second == n) return 2;

      columns[col].second++;
      if(columns[col].second == n) return 2;

      if(row == col){
      diagonal.second++;
      if(diagonal.second == n) return 2;
}
      if(row + col == n-1){
      reverseDiagonal.second++;
      if(reverseDiagonal.second == n) return 2;
}
}
return 0;
}
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */