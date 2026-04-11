class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> countMap;
        for (int n : nums) {
            countMap[n] += 1;
            if(countMap[n] > 1) return true;
        }
        return false;
    }
};