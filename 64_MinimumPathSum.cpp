//Recursion
class Solution {
public:
    int findMinPath(vector<vector<int>>& grid, int i , int j ){
        if (i < 0 || j < 0 ) return INT_MAX;
        else if (i == 0 && j == 0) return grid[i][j];

        return grid[i][j] + min(findMinPath(grid,i -1, j),findMinPath(grid, i , j-1));
    }
    int minPathSum(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        return findMinPath(grid, rows-1, cols-1);
    }
};

//Top down dp 
class Solution {
public:
    int findMinPath(vector<vector<int>>& grid,vector<vector<int>> &dp,int i , int j ){
        if (i < 0 || j < 0 ) return INT_MAX;
        else if (i == 0 && j == 0) return dp[i][j] = grid[i][j];

        if (dp[i][j]!=-1) return dp[i][j];

        return dp[i][j] =  grid[i][j] + min(findMinPath(grid,dp,i -1, j),findMinPath(grid,dp ,i , j-1));
    }
    int minPathSum(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<int>> dp(rows, vector<int>(cols,-1));
        return findMinPath(grid, dp ,rows-1, cols-1);
    }
};
//Buttom Up dp
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols  = grid[0].size();

        vector<vector<int>> dp(rows, vector<int>(cols));

        for (int i =0 ;i<rows; i++){
            for (int j = 0; j<cols ; j++ ){
                if (i == 0 && j == 0 ){
                    dp[i][j] = grid[i][j];
                }
                else {
                    int leftPathSum = (i == 0 ?  INT_MAX : dp[i-1][j]);
                    int topPathSum = (j == 0 ? INT_MAX : dp[i][j-1]);
                    dp[i][j] = grid[i][j]  + min(leftPathSum , topPathSum);
                }
            }
        }
        return dp[rows-1][cols-1];
    }
};