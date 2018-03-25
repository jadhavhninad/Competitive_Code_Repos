#https://leetcode.com/contest/weekly-contest-77/problems/max-increase-to-keep-city-skyline/

class Solution:
    def maxIncreaseKeepingSkyline(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """

        maxHor=[]
        maxvert=[]
        
        for i in range(len(grid)):
            maxh=0
            for j in range(len(grid[0])):
                maxh = grid[i][j] if maxh < grid[i][j] else maxh
            maxHor.append(maxh)
        
        for i in range(len(grid[0])):
            maxv=0
            for j in range(len(grid)):
                maxv = grid[j][i] if maxv < grid[j][i] else maxv
            maxvert.append(maxv)
        
        #print(maxHor)
        #print(maxvert)
        
        maxInc = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                smallmax = min(maxvert[i],maxHor[j])
                maxInc = maxInc + (smallmax - grid[i][j])

        return maxInc
    