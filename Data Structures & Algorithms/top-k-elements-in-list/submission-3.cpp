class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // we can create a map of pair data structure
        unordered_map<int, int> iMap;
        // loops through vector to create the map;
        for(int n : nums) {
            iMap[n]++;
        }
        // a vectore of pair instead
        vector<pair<int,int>> pairList;
        for(const auto& [key, value] : iMap){
            pairList.push_back({key, value});
        }        
        // perform a sort;
        sort(pairList.begin(), pairList.end(), [](auto& a, auto& b){
            return a.second > b.second; // descending by frequency
        });
        // take the first k after sort;
        vector<int> result;
        for(int i = 0; i < k; i++){
            result.push_back(pairList[i].first);
        }
        return result;
    }
};
