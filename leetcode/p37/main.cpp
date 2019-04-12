#include <iostream>
#include <vector>
using namespace std;
#define debug(x) cout<<#x<<": "<<x<<endl;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        if(write(board,0,0)){
            return;
        }
    }

    bool write(vector<vector<char>>& board,int i,int j){
        if(i==8 && j==9){
            return true;
        }else if(j==9){
            j%=9;
            i+=1;
            //cout<<i+1<<endl;
            return write(board,i,j);
        }else if(board[i][j] != '.'){
            return write(board,i,j+1);
        }


        vector<int>set1(10,1);

        for(int k=0;k<9;k++){

            if(board[i][k]!='.'){
                //debug(111);
                set1[ board[i][k] - '0' ] = 0;
            }
            if(board[k][j]!='.'){
                set1[ board[k][j] - '0' ] = 0;
            }

            pair<int ,int> hang = fang(i);
            pair<int ,int> lie = fang(j);

            for(int m = hang.first; m<=hang.second ;m++){
                for(int p =lie.first; p<=lie.second ;p++ ){
                    if(board[m][p]!='.'){
                        set1[ board[m][p] - '0' ] = 0;
                    }
                }
            }
        }

        for(int k=1;k<10;k++){

            if(set1[k]==1){
                board[i][j] = k + '0';

                if( write(board,i,j+1)){
                    return true;
                }else{
                    board[i][j] = '.';
                    continue;
                }
            }
        }
        return false;
    }

    pair<int ,int> fang(int i){
        pair<int,int> ret;
        if(i==0||i==1||i==2){
            ret.first = 0;
            ret.second = 2;
        }else if(i==3||i==4||i==5){
            ret.first = 3;
            ret.second = 5;
        }else if(i==6||i==7||i==8){
            ret.first = 6;
            ret.second = 8;
        }
        return ret;
    }
};

int main()
{
    ;
    vector<vector<char> > test = {
                {'5','3','.','.','7','.','.','.','.'},
                {'6','.','.','1','9','5','.','.','.'},
                {'.','9','8','.','.','.','.','6','.'},
                {'8','.','.','.','6','.','.','.','3'},
                {'4','.','.','8','.','3','.','.','1'},
                {'7','.','.','.','2','.','.','.','6'},
                {'.','6','.','.','.','.','2','8','.'},
                {'.','.','.','4','1','9','.','.','5'},
                {'.','.','.','.','8','.','.','7','9'}
            };

    for(auto i : test){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }

    Solution Solution1;
    Solution1.solveSudoku(test);
    cout<<endl<<endl;
    for(auto i : test){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }

    return 0;
}
