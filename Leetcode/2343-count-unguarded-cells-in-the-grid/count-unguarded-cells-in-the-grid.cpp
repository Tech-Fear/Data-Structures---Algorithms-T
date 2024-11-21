class Solution {
public:
    void markGuarded(int row,int col,vector<vector<int>>&grid){
        for(int i=row-1;i>=0;i--){
            if(grid[i][col]==1 || grid[i][col]==2) break;
            grid[i][col]=3;
        }
        for(int i=row+1;i<grid.size();i++){
            if(grid[i][col]==1 || grid[i][col]==2) break;
            grid[i][col]=3;
        }
        for(int i=col-1;i>=0;i--){
            if(grid[row][i]==1 || grid[row][i]==2) break;
            grid[row][i]=3;
        }
        for(int i=col+1;i<grid[0].size();i++){
            if(grid[row][i]==1 || grid[row][i]==2) break;
            grid[row][i]=3;
        }
    }
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>>grid(m,vector<int>(n,0));
        for(auto &guard:guards){
            grid[guard[0]][guard[1]]=1;
        }
        for(auto &wall:walls){
            grid[wall[0]][wall[1]]=2;
        }
        for(auto &guard:guards){
            markGuarded(guard[0],guard[1],grid);
        }
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0) count++;
            }
        }
        return count;
    }
};