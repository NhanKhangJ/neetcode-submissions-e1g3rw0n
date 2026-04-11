class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // write pointer — tracks where to place next valid element
        // starts at 0, only moves forward when a valid element is found
        int write = 0;

        // read pointer (i) — scans every element in the array
        for(int i = 0; i < (int)nums.size(); i++){

            // skip elements equal to val
            // only copy elements that are NOT val
            if(nums[i] != val) {

                // overwrite position write with current valid element
                // then advance write to next position
                nums[write] = nums[i];
                write++;
            } 
        }

        // write now equals the count of valid elements
        // first write elements of nums are the answer
        return write;
    }
};