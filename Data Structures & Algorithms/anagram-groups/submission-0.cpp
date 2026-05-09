class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> sMap;
        vector<vector<string>> result;
        for(string s : strs){
            string sortedKey = s;
            sort(sortedKey.begin(), sortedKey.end());
            sMap[sortedKey].push_back(s);
        }
        for(auto& pair : sMap) result.push_back(pair.second);
        return result; 
    }
};
