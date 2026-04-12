class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen;  // value → index
        for(int i = 0; i < (int)nums.size(); i++){
            int complement = target - nums[i];
            if(seen.count(complement)){
                return {seen[complement], i};  // found the pair
            }
            seen[nums[i]] = i;  // store current value and its index
        }
        return {};
    }
};
