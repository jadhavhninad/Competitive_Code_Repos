class Solution:
    def canJump(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        _size = len(nums)
        
        #print(_size)
        
        lastReachable = _size - 1;
        for i in range(_size-1, -1, -1):
            if(i + nums[i] >= lastReachable):
                lastReachable = i
            
           # print(lastReachable)
        
        return lastReachable == 0
