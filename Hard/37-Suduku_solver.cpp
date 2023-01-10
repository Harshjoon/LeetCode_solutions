class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solveSuduko(board);
    }

    bool solveSuduko(vector<vector<char>>& board){
        int row, col;
        char Num[9] = {'1','2','3','4','5','6','7','8','9'};
        if( !findUnassigned(board, row, col) ) return true;
        for(int num=1;num<=9;num++){
            if(numValid(board, row, col, num)){
                board[row][col] = Num[num-1];
                if(solveSuduko(board)) return true;
                board[row][col] = '.';
            }
        }
        return false;
    }

    bool findUnassigned(vector<vector<char>>& board, int & row, int & col){
        for(row=0; row<9; row++){
            for(col=0; col<9; col++){
                if(board[row][col]=='.') return true;
            }
        }
        return false;
    }

    bool inCol(vector<vector<char>>& board, int col, int num){
        char Num[9] = {'1','2','3','4','5','6','7','8','9'};
        for(int row=0; row < 9; row++){
            if( board[row][col] == Num[num-1] ) return true;
        }
        return false;
    }

    bool inRow(vector<vector<char>>& board, int row, int num){
        char Num[9] = {'1','2','3','4','5','6','7','8','9'};
        for(int col=0; col < 9; col++){
            if( board[row][col] == Num[num-1] ) return true;
        }
        return false;
    }

    bool inBox(vector<vector<char>>& board, int start_row, int start_col, int num){
        char Num[9] = {'1','2','3','4','5','6','7','8','9'};
        for(int row=0; row<3; row++){
            for( int col=0; col<3; col++ ){
                if( board[start_row + row][start_col + col] == Num[num-1] ) return true;
            }
        }
        return false;
    }

    bool numValid(vector<vector<char>>& board, int row, int col, int num){
        char Num[9] = {'1','2','3','4','5','6','7','8','9'};
        return board[row][col] == '.' 
            && !inCol(board, col, num)
            && !inRow(board, row, num)
            && !inBox(board, row - row%3, col - col%3, num);
    }

    void print(vector<vector<char>>& board){
        for(int row=0; row<9; row++){
            for(int col=0;col<9; col++){
                cout << board[row][col] << '.';
            }
            cout << endl;
        }
    }
};