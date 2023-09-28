class Solution:
    def search(self, nums: List[int], target: int) -> int:
      def binSearch(l, r, target):
        while(l <= r):
          mid = int((l + r) / 2)
          if nums[mid] == target:
            return mid
          elif nums[mid] > target:
            r = mid - 1
          else:
            l = mid + 1
        return -1
      
      if nums[len(nums) - 1] > nums[0]:
        return binSearch(0, len(nums) - 1, target)

      def searchTarget(l, r, target):
        if r - l <= 2:
          return nums.index(target) if target in nums else -1

        mid = int((l + r)/2)

        print(l, mid, r)

        if nums[mid] == target:
          return mid
        if nums[mid] < nums[l]:
          postMid = binSearch(mid + 1, r, target)
          return postMid if postMid != -1 else searchTarget(l, mid - 1, target)
        elif nums[mid] > nums[l]:
          preMid = binSearch(l, mid - 1, target)
          return preMid if preMid != -1 else searchTarget(mid + 1, r, target)

      return searchTarget(0, len(nums) - 1, target)

