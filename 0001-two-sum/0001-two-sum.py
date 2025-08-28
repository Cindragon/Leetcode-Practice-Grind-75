class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        record=dict()
        for index, value in enumerate(nums):
            if target-value in record:
                return [record[target-value], index]
            record[value]=index
        return []