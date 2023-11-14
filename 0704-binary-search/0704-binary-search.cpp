class Solution {
public:
    int search(vector<int>& nums, int target) {
        int front = 0;
        int back = nums.size() - 1;
        int bisector;

        while(front <= back){
            bisector = front + ((back - front) / 2);

            if(nums[bisector] == target){
                return bisector;
            }
            
            if(nums[bisector] < target){
                front = bisector + 1;
            } else {
                back = bisector - 1;
            }
        }

        return -1;

    }
};