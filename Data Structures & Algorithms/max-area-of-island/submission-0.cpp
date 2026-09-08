class Solution {
private:
    int dfs(int row,int col,vector<vector<int>>&grid,vector<vector<int>>&vis){
        int m=grid.size();
        int n=grid[0].size();
        if(row>=m || col>=n) return 0;
        vis[row][col]=1;
        int count=1;
        vector<int>dr={-1,0,1,0};
        vector<int>dc={0,-1,0,1};
        for(int i=0;i<4;i++){
            int nr=row+dr[i];
            int nc=col+dc[i];
            if(nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc]==1 && !vis[nr][nc]){
                count+=dfs(nr,nc,grid,vis);
            }
        }
        return count;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        int maxi=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    maxi=max(maxi,dfs(i,j,grid,vis));
                }
            }
        }
        return maxi;
    }
};
