class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> valueMap;

        for(int num : nums){
            
            if(valueMap[num] >= 1){
                return true;
            }

            valueMap[num]++;

        }

        return false;
    }
};

/*

Brute Force Approach - O(n^2)

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int size = nums.size();

        for(int i = 0; i < size - 1; i++){
            for(int j = i + 1; j < size; j++){
                if(nums[i] == nums[j]){
                    return true;
                }
            }
        }

        return false;
        
    }
};


Pre-sorting approach (using stdlib sort function) - O(n log n)

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int size = nums.size();

        for(int i = 0; i < size - 1; i++){
            if(nums[i] == nums[i+1]){
                return true;
            }
        }

        return false;
    }
};


Hashmap approach - O(n)



*/