class Solution:
    def isAnagram(self, stringOne: str, stringTwo: str) -> bool:
        if len(stringOne) != len(stringTwo):
            return False

        balDict = {}

        for char in stringOne:
            if char in balDict:
                balDict[char] += 1
            else:
                balDict[char] = 1
        
        for char in stringTwo:
            if char in balDict:
                balDict[char] -= 1
            else:
                return False
            
        isAnagram = False
        for freq in balDict.values():
            if freq != 0:
                return False


        return True

        