class Solution(object):
    def findMaxK(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums.sort()
        ret = -1
        
        i = 0
        j = len(nums)-1
        
        while(i < len(nums) and j >= 0 and nums[i] < 0 ):
            pos = abs(nums[i])
            # now compare pos and nums[j]
            if(pos == nums[j]):
                ret = max(ret, pos)
                break
            elif(pos < nums[j]):
                j -= 1
            else:
                i += 1
    
        
        return ret
        