class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> tripletResult;
        int target = 0;
        sort(nums.begin(),nums.end());

        for(int i = 0; i < nums.size(); i++){

            if(i > 0 && nums[i] == nums[i-1]){
                continue;
            }

            int j = i + 1;
            int k = nums.size() - 1;

            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum == target){
                    tripletResult.push_back({nums[i], nums[j], nums[k]});
                

                    while(j < k && nums[j] == nums[j+1]){
                        j++;
                    }

                    while(j < k && nums[k] == nums[k-1]){
                        k--;
                    }

                    j++;
                    k--;
                } else if (sum < target) {
                    j++;
                } else {
                    k--;
                }
            }
        }

        return tripletResult;

    }
};


/*

Using a set 

    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> tripletResult;
        set<vector<int>> tripletSet;
        int target = 0;

        sort(nums.begin(),nums.end());

        for(int i = 0; i < nums.size(); i++){
            int j = i + 1;
            int k = nums.size() - 1;

            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum == target){
                    tripletSet.insert({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                } else if (sum < target){
                    j++;
                } else {
                    k--;
                }
            }
        }


        for(auto triplet : tripletSet) {
            tripletResult.push_back(triplet);
        }

        return tripletResult;

    }
};

*/