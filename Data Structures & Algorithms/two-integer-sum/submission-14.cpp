class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen; // value -> original index
        for(int i = 0; i < nums.size(); i++){
            int complement = target - nums[i];
            if(seen.contains(complement)){
                return vector<int>{seen[complement], i};
            }
            seen[nums[i]] = i;
        }
        return vector<int>{-1, -1};
    }
};
