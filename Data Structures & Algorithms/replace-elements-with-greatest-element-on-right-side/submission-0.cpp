class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        // right to left instead
        if(arr.size() == 0) return arr;
        if(arr.size() == 1) return {-1};
        int maxRight = 0;
        for(int i = (int)arr.size() - 1; i >= 0; i--)    {
            if(i == (int)arr.size() - 1){
                maxRight = arr[i];
                arr[i] = -1;
            } else {
                if(arr[i] > maxRight) {
                    int temp = arr[i];  // save current value
                    arr[i] = maxRight;  // replace with maxRight
                    maxRight = temp;    // update maxRight
                } else {
                    arr[i] = maxRight;
                }
            }
        }


        return arr;
    }
};