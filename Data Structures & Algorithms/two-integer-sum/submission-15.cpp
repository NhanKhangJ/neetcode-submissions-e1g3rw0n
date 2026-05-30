class Solution {
public:
    // Old thinking: "find two numbers that add up to target"
    // New thinking: "for each number, has its partner shown up before?"
    vector<int> twoSum(vector<int>& nums, int target) {
        // create a map to track those seen value;
        unordered_map<int, int> seen;
        for(int i =0; i < nums.size();i++){
            //Complement refers to something that completes, enhances, or makes perfect when paired with something else.
            int complement = target - nums[i];
            //unorderd_map syntax to check for cotain key or not;
            // in this case if contain we found the index value 
            if(seen.contains(complement)){
                return vector<int>{seen[complement], i};
            }

            seen[nums[i]] = i;
        }
        return vector<int>{-1, -1};
    }
};
