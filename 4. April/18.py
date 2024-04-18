class Solution(object):
    
    
    def addScore(self,i,j,grid,rows,cols):
        score = 0
        
        # check all four directions one by one
        if i-1 < 0 or grid[i-1][j] == 0:
            score += 1
        if i+1 >= rows or grid[i+1][j] == 0:
            score += 1
        if j-1 < 0 or grid[i][j-1] == 0:
            score += 1
        if j+1 >= cols or grid[i][j+1] == 0:
            score += 1
        
        return score
    
    def islandPerimeter(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        score = 0
        rows = len(grid)
        cols = len(grid[0])
        
        for i in range(rows):
            for j in range(cols):
                if(grid[i][j] == 1):
                    score += self.addScore(i, j, grid,rows,cols)
            
        return score