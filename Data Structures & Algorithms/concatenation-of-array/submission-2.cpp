class Solution {
public:
    void resize(vector<int>& nums, int newSize){
        vector<int> temp(newSize, 0);
        for(int i = 0; i < (int)nums.size(); i++){
            temp[i] = nums[i];
        }
        nums = temp;
    }
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> ans = nums;
        resize(ans, nums.size() * 2);
        for(int i = 0; i < nums.size(); i++){
            ans[i+nums.size()] = nums[i];
        }
        return ans;
    }
};