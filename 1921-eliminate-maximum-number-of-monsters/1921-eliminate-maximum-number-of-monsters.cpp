using namespace std;
class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int max = dist.size();
        vector<double> minutesTillCity(max);
        
        for (int i = 0; i < max; ++i) {
            minutesTillCity[i] = static_cast<double>(dist[i]) / speed[i];
        }
        
        sort(minutesTillCity.begin(), minutesTillCity.end());
        
        for (int i = 0; i < max; ++i) {
            if (minutesTillCity[i] <= i) {
                return i;
            }
        }
        
        return max;
    };
};