#include <map>
using namespace std;
class Solution {
public:
    // O(n) - one map solution
    bool isAnagram(string s, string t) {
        map<char, int> fMap;

        for(char letter : s){
            fMap[letter]++;
        }

        for(char letter : t){
            fMap[letter]--;
        }

        for(char letter : s){
            if(fMap[letter] != 0){
                return false;
            }
        }

        for(char letter : t){
            if(fMap[letter] != 0){
                return false;
            }
        }

        return true;
    }
};