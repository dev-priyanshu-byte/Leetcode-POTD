class Solution {
public:
    bool check(int x,int y,vector<vector<char>>& board){
        map<char,int> mp;
        for(int i=x;i<x+3;i++)
        {
            for(int j=y;j<y+3;j++)
            {
                if(board[i][j]=='.')
                continue;
                //cout<<i<<" "<<j<<board[i][j]<<endl;
                if(mp[board[i][j]]==1)
                return true;
                mp[board[i][j]]++;
            }
        }
        cout<<endl<<endl;
        return false;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++)
        {
            map<char,int> mp;
            for(int j=0;j<9;j++)
            {
                if(board[i][j]=='.')
                continue;
                //cout<<i<<" "<<j<<" "<<board[i][j]<< endl;
                if(mp[board[i][j]]==1)
                return false;
                mp[board[i][j]]++;
            }
        }
        for(int j=0;j<9;j++)
        {
            map<char,int> mp;
            for(int i=0;i<9;i++)
            {
                if(board[i][j]=='.')
                continue;
                //cout<<i<<" "<<j<<endl;
                if(mp[board[i][j]]==1)
                return false;
                mp[board[i][j]]++;
            }
        }
        for(int i=0;i<9;i+=3)
        {
            for(int j=0;j<9;j+=3)
            {
                if(check(i,j,board))
                return false;
            }
        }
        return true;
    }
};