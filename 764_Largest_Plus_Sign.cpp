//https://leetcode.com/contest/weekly-contest-67/problems/largest-plus-sign/
//764. Largest Plus Sign

class Solution {
public:
    int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
        
        //initialize with N as its the max + 1 value.
        vector<vector<int>> grid(N, vector<int>(N,N));
        int _msize = mines.size();
        int res=0;
        
          /*for(int i=0; i<N; i++){
            for(int j=0 ;j<N; j++)
               cout << grid[i][j] << ",";
            cout << endl;
        }*/
        
        for(int i=0; i<_msize; i++){
            grid[mines[i][0]][mines[i][1]] = 0;
        }
        
        for(int i=0; i<N;i++){
            for(int j=0, k=N-1, l=0, r=0, u=0, d=0; j<N; j++, k--){
                
                l=(grid[i][j] == 0 ? 0 : l+1);
                grid[i][j] = (grid[i][j] < l) ? grid[i][j] : l;
                
                r=(grid[i][k] == 0 ? 0 : r+1);
                grid[i][k] = (grid[i][k] < r) ? grid[i][k] : r;
                
                u=(grid[j][i] == 0 ? 0 : u+1);
                grid[j][i] = (grid[j][i] < u) ? grid[j][i] : u;
                
                d=(grid[k][i] == 0 ? 0 : d+1);
                grid[k][i] = (grid[k][i] < d) ? grid[k][i] : d;
            }
        }
        
        for(int i=0; i<N; i++){
            for(int j=0 ;j<N; j++)
                res = max(res,grid[i][j]);
        }
        
        return res;
    }
    
    int orderOfLargestPlusSign2(int N, vector<vector<int>>& mines) {
    vector<vector<int>> grid(N, vector<int>(N, N));
        
    for (auto& m : mines) {
        grid[m[0]][m[1]] = 0;
    }
        
    for (int i = 0; i < N; i++) {
        for (int j = 0, k = N - 1, l = 0, r = 0, u = 0, d = 0; j < N; j++, k--) {
            grid[i][j] = min(grid[i][j], l = (grid[i][j] == 0 ? 0 : l + 1));
            grid[i][k] = min(grid[i][k], r = (grid[i][k] == 0 ? 0 : r + 1));
            grid[j][i] = min(grid[j][i], u = (grid[j][i] == 0 ? 0 : u + 1));
            grid[k][i] = min(grid[k][i], d = (grid[k][i] == 0 ? 0 : d + 1));
        }
    }
        
    int res = 0;
        
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            res = max(res, grid[i][j]);
        }
    }
        
    return res;
}
};
