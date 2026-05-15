class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        // Initialize prefix array with all 1s, size = nums.size()
        // prefixMultiple[i] = product of all elements to the LEFT of i
        vector<int> prefixMultiple = vector<int>(nums.size(), 1);

        // Tracks the running product as we scan left to right
        int currentLeft = 1;

        // Start at i=1, index 0 has nothing to its left so it stays 1
        for(int i = 1; i < nums.size(); i++){

            // Accumulate the product of the previous element
            currentLeft *= nums[i - 1];

            // Store left product at index i
            prefixMultiple[i] = currentLeft;
        }

        // Initialize suffix array with all 1s, size = nums.size()
        // suffixMultiple[i] = product of all elements to the RIGHT of i
        vector<int> suffixMultiple = vector<int>(nums.size(), 1);

        // Tracks the running product as we scan right to left
        int currentRight = 1;

        // Start at second-to-last, last index has nothing to its right so it stays 1
        for(int i = nums.size() - 2; i >= 0; i--){

            // Accumulate the product of the next element
            currentRight *= nums[i + 1];

            // Store right product at index i
            suffixMultiple[i] = currentRight;
        }

        // Initialize result array with all 1s, size = nums.size()
        vector<int> result = vector<int>(nums.size(), 1);

        // For each index, multiply left product * right product
        for(int i = 0; i < nums.size(); i++){

            // result[i] = product of all elements except nums[i]
            result[i] = prefixMultiple[i] * suffixMultiple[i];
        }

        // Return the final result array
        return result;
    }
};