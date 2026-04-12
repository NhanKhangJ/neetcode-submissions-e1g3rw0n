class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        unordered_map<char, int> stringMap;
        int matchCount = t.length();
        for(int i =0; i < (int)s.length(); i++){
            stringMap[s[i]] += 1;
        }
        for(int i = 0; i < (int)t.length(); i++){
            if(stringMap.count(t[i])) {
                stringMap[t[i]]--;        // use one occurrence
                matchCount--;
                if(stringMap[t[i]] == 0) stringMap.erase(t[i]);  // remove when exhausted
            }
        }
        return matchCount == 0;
    }
};
