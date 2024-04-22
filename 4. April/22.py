class Solution(object):
    
    def fillNeighbours(self, que, curr, dead):
        for i in range(4):
            ch = curr[i]
            
            dec = '9' if ch == '0' else chr(ord(ch) - 1)
            inc = '0' if ch == '9' else chr(ord(ch) - 1)
            
            curr = curr[:i] + dec + curr[i+1:]
            if curr not in dead:
                dead.add(curr)
                que.append(curr)
                
            curr = curr[:i] + inc + curr[i+1:]
            if curr not in dead:
                dead.add(curr)
                que.append(curr)
                
            curr = curr[:i] + ch + curr[i+1:]
        
    def openLock(self, deadends, target):
        """
        :type deadends: List[str]
        :type target: str
        :rtype: int
        """
        dead = set(deadends)
        
        start = "0000"
        
        if "0000" in dead:
            return -1
        
        que = []
        que.append(start)
        
        level = 0
        while(len(que) != 0):
            n = len(que)
            
            while(n != 0):
                curr = que[0]
                que.pop(0) #removes the number at index 0
                
                if curr == target:
                    return level
                
                self.process(que, curr, dead)
                n -= 1
                
            level += 1
            
        return -1
        