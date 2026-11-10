class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<int>>temp(m,vector<int>(n,0));
        int dx[]={-1,-1,-1,0,0,1,1,1};
        int dy[]={-1,0,1,-1,1,-1,0,1};

        // first pass
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int count=0;
                for(int k=0;k<8;k++){
                    int nr=i+dx[k];
                    int nc=j+dy[k];
                    if(nr>=0 && nc>=0 && nr<m && nc<n){
                        if(board[nr][nc]==1){
                            count++;
                        }
                    }
                }
                if(board[i][j]==1){
                    if(count==2 || count ==3){
                        temp[i][j]=1;
                    }
                    else{
                        temp[i][j]=0;
                    }
                }
                else{
                    if(count==3){
                        temp[i][j]=1;
                    }
                    else{
                        temp[i][j]=0;
                    }
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                board[i][j]=temp[i][j];
            }
        }

    }
};