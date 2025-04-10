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
/*
用一個26格陣列來計算第一個字串每個字母出現的次數
再遍歷第二個字串有重複的減減
最後計算字串中如果有非0的值就return false(代表有多出字母)
*/
