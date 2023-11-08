class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int xDestination = abs(sx - fx);
        int yDestination = abs(sy - fy);

        int minTimeSteps = min(xDestination, yDestination) + abs(yDestination - xDestination);

        if(minTimeSteps == 0){
            if(t == 1){
                return false;
            } else {
                return true;
            }
        }

        return t >= minTimeSteps;
    }
};