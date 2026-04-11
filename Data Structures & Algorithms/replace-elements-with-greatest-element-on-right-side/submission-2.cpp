class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        // last element always becomes -1
        // save it as starting maxRight before overwriting
        int maxRight = arr[arr.size() - 1];
        arr[arr.size() - 1] = -1;

        // walk right to left — skip last element, already handled
        for(int i = (int)arr.size() - 2; i >= 0; i--){
            // save current value before overwriting
            int temp = arr[i];

            // replace current element with the max to its right
            arr[i] = maxRight;

            // update maxRight if current value was larger
            if(temp > maxRight) maxRight = temp;
        }
        return arr;
    }
};