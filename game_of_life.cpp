class Solution {
public:
    void check(vector<vector<int>>& board,int i,int j)
    {
           int n = board.size(), m = n ? board[0].size() : 0;
    
         int count=0;
             for (int I = max(i - 1, 0); I < min(i + 2, n); ++I) {

                    for (int J = max(j - 1, 0); J < min(j + 2, m); ++J) {

                        count += board[I][J] & 1;

                    }

                }
        if((count==4&&board[i][j])||count==3)
           board[i][j]|=2;
         
    }
    void gameOfLife(vector<vector<int>>& b) {
          int n = b.size(), m = n ? b[0].size() : 0;
      // vector<vector<int> > vec( n , vector<int> (m, 0)); 
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                
                    check(b,i,j);
                
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                b[i][j]>>=1;
            }
        }
        
  
    }
};