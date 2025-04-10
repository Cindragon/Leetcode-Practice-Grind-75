class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()) return false;
        int alphacount[26];
        for(const auto &c:s){
            alphacount[c-'a']++;
        }
        for(const auto &c:t){
            alphacount[c-'a']--;
        }
        for(const auto &i:alphacount){
            if(i!=0) return false;
        }
        return true;
    }
};