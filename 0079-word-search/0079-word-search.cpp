class Solution {
public:
    bool back_track(int r, int c, vector<vector<char>>& board, string word)
    {
        if (word.size()==0)
            return true;
        if (r<0 || r>=board.size() || c<0 || c>=board[0].size() || board[r][c]!=word[0])
            return false;
        int r_id[4]={0,1,0,-1};
        int c_id[4]={1,0,-1,0};
        bool ret=false;
        board[r][c]='#';
        for(int i=0; i<4; i++)
        {
            string next;
            next.assign(word,1,word.size()-1);
            ret=back_track(r+r_id[i], c+c_id[i], board, next);
            if (ret == true)
                break;
        }
        board[r][c]=word[0];
        return ret;
    }
    bool exist(vector<vector<char>>& board, string word) {
         int rows=board.size();
         int cols=board[0].size();
        vector<vector<char>> int_board;
        int i,j;
         for( i=0; i<board.size(); i++)
         {
             vector<char> v;
             for( j=0; j<board[0].size(); j++)
             {
                 v.push_back(board[i][j]);
             }
             int_board.push_back(v);
         }
        bool ret;
        ret=false;
         for( i=0; i<int_board.size(); i++)
         {
             for( j=0; j<int_board[0].size(); j++)
             {
                 ret=back_track(i,j,int_board,word);
                 if (ret==true)
                     return ret;
             }
         }
        return ret;
    }
};