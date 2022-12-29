class Solution:
    def search(self, nums: List[int], target: int) -> int:
        if len(nums) == 0:
            return -1
        mid = len(nums) // 2
        if nums[mid] == target:
            print(target, nums[0])
            return mid
        elif nums[mid] < target:
            temp = self.search(nums[mid + 1:], target)
            return mid + 1 + temp if temp != -1 else -1
        else:
            temp = self.search(nums[:mid], target)
            return temp if temp != -1 else -1
