#include <map>
using namespace std;
class Solution {
public:
    // 2 map solution - O(n) time complexity
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()){
            return false;
        }


        map<char, int> sMap;
        map<char, int> tMap;

        for(char letter : s){
            sMap[letter]++;
        }

        for(char letter : t){
            tMap[letter]++;
        }

        for(const auto& entry : sMap){
            char letter = entry.first;
            int frequencySVect = entry.second;

            if(tMap.find(letter) == tMap.end() || tMap[letter] != frequencySVect) {
                return false;
            }
        }
        
        for(const auto& entry : tMap){
            char letter = entry.first;
            int frequencyTVect = entry.second;

            if(sMap.find(letter) == sMap.end() || sMap[letter] != frequencyTVect){
                return false;
            }
        }

        return true;


    }
};