class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        // Step 1: Count frequency of each number
        // ex: [1,1,2,3,3,3] → {1:2, 2:1, 3:3}
        unordered_map<int, int> iMap;
        for(int n : nums) {
            iMap[n]++;
        }

        // Step 2: Dump map into a vector of pairs so we can sort it
        // ex: {1:2, 2:1, 3:3} → [(1,2), (2,1), (3,3)]
        //      first=number, second=frequency
        vector<pair<int,int>> pairList;
        for(const auto& [key, value] : iMap){
            pairList.push_back({key, value});
        }        

        // Step 3: Sort by frequency (second) descending
        // ex: [(1,2), (2,1), (3,3)] → [(3,3), (1,2), (2,1)]
        //      most frequent first
        sort(pairList.begin(), pairList.end(), [](auto& a, auto& b){
            return a.second > b.second;
        });

        // Step 4: Take first k elements (most frequent winners)
        // ex: k=2 → grab index 0 and 1 → [3, 1]
        //     we push first (the number) not second (the frequency)
        vector<int> result;
        for(int i = 0; i < k; i++){
            result.push_back(pairList[i].first);
        }

        return result;
    }
};