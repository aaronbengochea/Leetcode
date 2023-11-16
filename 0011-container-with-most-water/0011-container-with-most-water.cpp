class Solution {
public:
    int maxArea(vector<int>& height) {
        int front = 0;
        int back = height.size() - 1;
        int maxWater = 0;

        while(front <= back){
            
            if(maxWater < ((min(height[front],height[back])) * (back - front))){
                maxWater = (min(height[front],height[back])) * (back - front);
                if(height[front] >= height[back]){
                    back--;
                } else {
                    front++;
                }
            } else {
                if(height[front] >= height[back]){
                    back--;
                } else {
                    front++;
                }
            }
        }

        return maxWater;
        
    }
};