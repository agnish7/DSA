class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        maxDeque  = deque()
        res = []

        for i in range(k):
            if len(maxDeque) == 0:
                maxDeque.appendleft(i)
                continue
            else:
                while(len(maxDeque) > 0 and nums[i] >= nums[maxDeque[0]]):
                    maxDeque.popleft()
                maxDeque.appendleft(i)
        
        for i in range(k, len(nums)):
            res.append(nums[maxDeque[-1]])

            while(len(maxDeque) > 0 and nums[i] >= nums[maxDeque[0]]):
                maxDeque.popleft()
            maxDeque.appendleft(i)
            
            while(len(maxDeque) > 0 and maxDeque[-1] < i - k + 1):
                maxDeque.pop()

        if len(maxDeque) > 0:
            res.append(nums[maxDeque[-1]])
        return res
