class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int best = 0, current = 0;
        for (int n : nums) {
            if (n == 1) {
                current++;
                if (current > best) best = current;
            } else {
                current = 0;
            }
        }
        return best;
    }
};
