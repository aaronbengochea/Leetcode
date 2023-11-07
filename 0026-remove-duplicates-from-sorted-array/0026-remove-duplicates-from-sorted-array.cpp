#include <map>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        map<int, int> uniqueValuesMap;
        int mapIndex = 0;

        for(int i : nums) {

            if(uniqueValuesMap.find(i) == uniqueValuesMap.end()){
                uniqueValuesMap[i] = mapIndex;
                mapIndex++;
            }
        }

        int updateIndex = 0;
        for(const auto& pair : uniqueValuesMap){
            int value = pair.first;
            nums[updateIndex] = value;
            updateIndex++;
        }

        return updateIndex;
    }
};