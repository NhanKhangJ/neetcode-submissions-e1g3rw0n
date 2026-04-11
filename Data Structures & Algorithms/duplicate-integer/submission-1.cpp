class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<string, int> countMap;
        for (int n : nums) {
            string key = to_string(n);
            countMap[key] += 1;
            if(countMap[key] > 1) return true;
        }
        return false;
    }
};