class NumArray {
public:
    vector<int> prefixSumArray;
    NumArray(vector<int>& nums) {
        int sum = 0;
        for(int n : nums){
            sum += n;
            prefixSumArray.push_back(sum);
        }
    }
    
    int sumRange(int left, int right) {
        int leftPrefix = left > 0 ? prefixSumArray[left - 1] : 0;
        int rightPrefix = prefixSumArray[right];
        return rightPrefix - leftPrefix;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */