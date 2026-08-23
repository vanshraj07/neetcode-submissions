class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int,int>mpp;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    mpp[board[i][j]-'0']++;
                }
            }
            for(auto it:mpp){
                if(it.second>1) return false;
            }
            mpp.clear();
        }
        for(int j=0;j<9;j++){
            for(int i=0;i<9;i++){
                if(board[i][j]!='.'){
                    mpp[board[i][j]-'0']++;
                }
            }
            for(auto it:mpp){
                if(it.second>1) return false;
            }
            mpp.clear();
        }
        for(int row=0;row<9;row+=3){
            for(int col=0;col<9;col+=3){
                for(int i=row;i<row+3;i++){
                    for(int j=col;j<col+3;j++){
                        if(board[i][j]!='.'){
                            mpp[board[i][j]-'0']++;
                        }
                    }
                }
                for(auto it:mpp){
                    if(it.second>1) return false;
                }
                mpp.clear();
            }
        }
        return true;
    }
};
