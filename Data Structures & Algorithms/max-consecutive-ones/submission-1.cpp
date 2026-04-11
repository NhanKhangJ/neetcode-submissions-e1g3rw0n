class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int current =0; // current streak of 1s
        int best =0;  // best streak seen so far
        for(int i = 0; i < (int)nums.size(); i++){
            if(nums[i] == 1) {
                current += 1;
                if(current > best) best = current;
            } 
            if(nums[i] == 0) current = 0;
        }
        return best;
    }
};