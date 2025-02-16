class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // row
        // column
        // grid

        if(!rowValid(board)) return false;
        if(!colValid(board)) return false;
        if(!gridValid(board)) return false;
        return true;
    }


    bool rowValid(vector<vector<char>>& board)
    {
        // traverse through row
        // find repeating

        for(int i=0;i<9;i++)
        {
            vector<char> row = board[i];
            if(isDuplicate(row)) {
                return false;
            }
        }
        return true;
    }

    bool colValid(vector<vector<char>> & board){
        for(int i=0;i<9;i++){
            vector<char> col;
            for(int j=0;j<9;j++){

                //cout << "error: " << board[j][i];
                col.push_back(board[j][i]);
            }

            if(isDuplicate(col)) return false;
        }
        return true;
    }

    bool gridValid(vector<vector<char>> & board)
    {
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++){
                vector<char> grid;

                for(int i_=0;i_<3;i_++){
                    for(int j_=0;j_<3;j_++)
                    {
                        grid.push_back(board[i*3+i_][j*3+j_]);
                    }
                }

                if(isDuplicate(grid)){
                    return false;
                } 
            }
        }
        return true;
    }


    bool isDuplicate(vector<char>& row){
        // mapping of numbers and count
        unordered_map<char,int> mapping;

        for(int element: row)
        {
            if(mapping[element]){
                return true;
            } 
            
            if(element=='.') continue;
            else{
                mapping[element]++;
            }
        }
        return false;
    }

};