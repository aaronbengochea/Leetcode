class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
            if len(nums) == 2:
                return [0,1]
            
            balDict = {}

            for i, num in enumerate(nums):
                difference = target - num

                if difference in balDict and balDict[difference] != i:
                    return [balDict[difference], i]
                
                balDict[num] = i


                