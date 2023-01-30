// Hash function 
// struct hashFunction
// {
// size_t operator()(const pair<int , 
//                     int> &x) const
// {
//     return x.first ^ x.second;
// }
// };

class Solution {
public:
    vector<int> rowOffset = {0, 0 , 1, -1};
    vector<int> colOffset = {1, -1, 0, 0};


    bool search(vector<vector<char>>& board, int row, int col, int wordIndex , string word){
        // base case
        if(wordIndex == word.size()){
            return true;
        }

        if(row < 0 ||
           row >= board.size() ||
           col < 0 ||
           col >= board[0].size() ||
           board[row][col] != word[wordIndex]
        //    uset.count({row, col})
           ){
            return false;
        }


        // uset.insert({row, col});
        char tmp = board[row][col];
        board[row][col] = '#';

        for(int d = 0 ; d < 4 ; d++){
            if(search(board, row+rowOffset[d], col+colOffset[d], wordIndex+1, word)){
                return true;
            }
        }

        board[row][col] = tmp;

        // bool result = search(board, row+1, col, wordIndex+1, word, uset) || 
        //               search(board, row-1, col, wordIndex+1, word, uset) ||
        //               search(board, row, col+1, wordIndex+1, word, uset) ||
        //               search(board, row, col-1, wordIndex+1, word, uset);
        
        // uset.erase({row, col});

        return false;
    }



    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        // unordered_set<pair<int, int>, hashFunction> uset;
        bool result = false;

        for(int i = 0; i < n ; i++){
            for(int j = 0 ; j < m ; j++){              
                result = search(board, i, j, 0, word);
                if(result) return true;
                }
            }   
            return false;
        }
};
