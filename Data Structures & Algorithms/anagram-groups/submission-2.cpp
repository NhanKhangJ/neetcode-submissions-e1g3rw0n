class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // I'm going to use a map of 'cat' : vector['cat', 'act];
        unordered_map<string, vector<string>> strListMap;
        vector<vector<string>> result;
        // to be able to do this we need to sort the each string of character in the right order before we put them to the map 
        for(string s : strs){
            string key = s;
            // sort return void watch out for this
            sort(key.begin(), key.end());
            strListMap[key].push_back(s);
        }
        // loop throught the unorderedMap
        for (const auto& [key, value] : strListMap) {
            result.push_back(value);
        }
        return result;
    }
};
