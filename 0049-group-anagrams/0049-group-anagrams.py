class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        finalMap = {}

        for word in strs:
            sortedWord = ''.join(sorted(word))
            if sortedWord in finalMap:
                finalMap[sortedWord].append(word)
            else:
                finalMap[sortedWord] = [word]

        finalList = finalMap.values()
        
        return finalList
        