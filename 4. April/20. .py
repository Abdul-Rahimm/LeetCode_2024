class Solution(object):
    
    def DFS(self, i,j,land,rows,cols):
        row = [i,j]
        
        while i+1 < rows and land[i+1][j] == 1:
            i += 1
        while j+1 < cols and land[i][j+1] == 1:
            j += 1
        
        for x in range(row[0],i+1):
            for y in range(row[1], j+1):
                land[x][y] = -1
                
        row.append(i)
        row.append(j)
        
        return row
    
    def findFarmland(self, land):
        """
        :type land: List[List[int]]
        :rtype: List[List[int]]
        """
        ans = []

        rows = len(land)
        cols = len(land[0])

        for i in range(rows):
            for j in range(cols):

                if(land[i][j] == 1):
                    row = self.DFS(i,j,land,rows,cols)
                    ans.append(row)

        return ans