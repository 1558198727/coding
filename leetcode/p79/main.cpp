#include <iostream>
#include <vector>
#include <string>

using namespace std;
#define debug(x) cout<<#x<<": "<<x<<endl;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(word.size()==0){
            return true;
        }
        vector<pair<int,int>> ps;
        //找到所有合法起始点
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                if(board[i][j]==word[0]){
                    pair<int,int> pt(i,j);
                    ps.push_back(pt);
                }
            }
        }
        //从起始点开始找
        for(auto i : ps){
            if(findw(board,word,i.first,i.second)){
                return true;
            }
        }
        return false;
    }

    bool findw(vector<vector<char>>& board,string word,int x,int y){
        debug(word)
        if(x<0 || x>=board.size() || y<0 || y>=board[0].size()){
            return false;
        }
        if(word[0]!=board[x][y]){
            return false;
        }else if(word.size()==1){//找完了
            return true;
        }
        char pre = board[x][y];
        board[x][y]='0';
        if( findw(board,word.substr(1),x+1,y)
           ||findw(board,word.substr(1),x-1,y)
           ||findw(board,word.substr(1),x,y+1)
           ||findw(board,word.substr(1),x,y-1)){
            return true;
        }else{
            board[x][y]=pre;
            return false;
        }
        return false;
    }
};

int main()
{
    Solution Solution1;
    vector<vector<char>> board ={
                        {'A'}
    };
    cout<<Solution1.exist(board,"A")<<endl;
    return 0;
}
