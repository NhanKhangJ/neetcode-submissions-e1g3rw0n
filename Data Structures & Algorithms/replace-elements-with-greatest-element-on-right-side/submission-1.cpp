class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int maxRight = arr[arr.size() - 1];  
        for(int i = arr.size() - 1; i >= 0; i--) {
            int temp = arr[i];
            arr[i] = maxRight;
            if(temp > maxRight) maxRight = temp;
        }
        arr[arr.size()-1] = -1;
        return arr;
    }
};