class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> nMap;
        for(int n : nums){
            nMap[n] += 1;
        }
        vector<pair<int,int>> pairList;
        for(auto& key : nMap){
            pairList.push_back({key.second, key.first});  // {count, number}
        }
        sort(pairList.begin(), pairList.end(), greater<>());
        vector<int> result;
        // now write the final loop yourself 
        for(int i = 0; i < k; i++){
            result.push_back(pairList[i].second);
        }
        // grab first k entries from pairList,
        // push their .second (the number) into a result vector
        return result;
    }
};