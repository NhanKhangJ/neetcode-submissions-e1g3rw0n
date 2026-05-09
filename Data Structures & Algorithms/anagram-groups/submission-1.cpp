// class Solution {
// public:
//     vector<vector<string>> groupAnagrams(vector<string>& strs) {
//         unordered_map<string, vector<string>> sMap;
//         vector<vector<string>> result;
//         for(string s : strs){
//             string sortedKey = s;
//             sort(sortedKey.begin(), sortedKey.end());
//             sMap[sortedKey].push_back(s);
//         }
//         for(auto& pair : sMap) result.push_back(pair.second);
//         return result; 
//     }
// };

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> sMap;
        vector<vector<string>> result;
        for(string& s : strs){
            // count occurrences of each letter
            vector<int> count(26, 0);
            for(char c : s) count[c - 'a']++;
            
            // build a key from the count array
            string key = "";
            for(int n : count) key += to_string(n) + "#";
            
            sMap[key].push_back(s);
        }
        for(auto& pair : sMap) result.push_back(pair.second);
        return result; 
    }
};