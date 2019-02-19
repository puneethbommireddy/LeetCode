class Solution {
    vector<vector<string>> boards;
    int n;
public:
    vector<vector<string>> solveNQueens(int n) {
        boards = {};
        this->n = n;
        int v[n]; for(int i=0;i<n;++i) v[i] = -1;
        placeQueens(0,v);
        return boards;
    }
    void placeQueens(int row_no,int* v)
    {
        if(row_no==n)
        {
            string s(n,'.');
            vector<string> board(n,s);
            for(int j=0;j<n;j++) if(v[j] !=-1) board[v[j]][j] = 'Q';
            boards.push_back(board);
        }
        else
        {
            //cout<<row_no<<endl;
            bool l[n]={false},r[n]={false};
            for(int j=0;j<n;++j)
            {
                //cout<<v[j]<<" ";
                if(v[j] != -1)
                {
                    int dist = row_no - v[j];
                    if(j>=dist) l[j-dist] = true;
                    if(j+dist < n) r[j+dist] = true;
                    //cout<<j<<" "<<v[j]<<endl;
                }
            }
            //cout<<endl;
            for(int j=0;j<n;++j) 
            {
                if(v[j] == -1 && !l[j] && !r[j])
                {
                    v[j] = row_no;
                    placeQueens(row_no+1,v);
                    v[j] = -1;
                }
            }
        }
    }
};