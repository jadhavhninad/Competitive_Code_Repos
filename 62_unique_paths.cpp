//62. Unique Paths
//https://leetcode.com/problems/unique-paths/description/

class Solution {
public:

    //Using DP with optimal solution.
    int uniquePaths(int m, int n) {
        if (m > n) return uniquePaths(n, m);
        vector<int> cur(m, 1);
        for (int j = 1; j < n; j++)
            for (int i = 1; i < m; i++)
                cur[i] += cur[i - 1]; 
        return cur[m - 1];
    }
    
    //Using backtracking
    int uniquePaths2(int m, int n) {
        
        vector<vector<int>> pathVal={};
        
        for(int i=0;i<m;i++){
            vector<int> temp(n,0);
            pathVal.push_back(temp);
        }
        
        return findDestMemo(m,n,0,0,pathVal);
        //return pathVal[0][0];
        
    }
    
    int findDestMemo(int row, int column, int pos_m, int pos_n, vector<vector<int>>& pathVal){
        //int found = 0;
        
        if(pos_m == row-1 && pos_n == column - 1){
            return 1;
        }
        else{
            //Walk right and search.
            if(pos_n+1 < column){
                if(pathVal[pos_m][pos_n+1] > 0)
                    pathVal[pos_m][pos_n] += pathVal[pos_m][pos_n+1];
                else
                    pathVal[pos_m][pos_n] += findDestMemo(row,column,pos_m,pos_n+1,pathVal);
            }
            //Since we need to find all possible paths, check down as well.
            
            if(pos_m+1 < row){
                if(pathVal[pos_m+1][pos_n] > 0)
                    pathVal[pos_m][pos_n] += pathVal[pos_m+1][pos_n];
                else
                    pathVal[pos_m][pos_n] += findDestMemo(row,column,pos_m+1,pos_n,pathVal);
            }
        }
        
        return pathVal[pos_m][pos_n];
    }
    
    
    //Without memoization, we recalculate the paths which have already been calculated. This causes TLE.
    int findDest(int row, int column, int pos_m, int pos_n){
        int found = 0;
        
        if(pos_m >= row || pos_n >= column)
            return found;
    
        if(pos_m == row-1 && pos_n == column - 1){
            return 1;
        }
        else{
            //Walk right and search.
            found += findDest(row,column,pos_m,pos_n+1);
            
            //Since we need to find all possible paths, check down as well.
            found+= findDest(row,column,pos_m+1,pos_n);
        }
        
        return found;
    }
};
