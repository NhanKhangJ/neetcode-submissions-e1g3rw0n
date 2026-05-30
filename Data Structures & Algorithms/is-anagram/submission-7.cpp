class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;

        unordered_map<char, int> fMap;
        unordered_map<char, int> sMap;

        for(int i = 0; i < s.length(); i++){
            fMap[s[i]]++;
            sMap[t[i]]++;
        }

        return fMap == sMap; // ✅ directly compare maps
    }
};
