#include <map>
using namespace std;
class Solution {
public:
    // O(n log n) - becuase of the sorting time
    bool isAnagram(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        return s == t;
    }
};