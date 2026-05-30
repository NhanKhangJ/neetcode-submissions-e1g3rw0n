class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> numMap;
        for(int n : nums){
            numMap[n] += 1;
            if(numMap[n] > 1) return true;
        }
        return false;
    }
};