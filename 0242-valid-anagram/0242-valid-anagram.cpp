class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length())  return false;
        int alphacount[26];
        for(const auto&c:s){
            alphacount[c-'a']++;
        }
        for(const auto&c:t){
            alphacount[c-'a']--;
        }
        for(const auto&i:alphacount){
            if(i!=0)    return false;
        }
        return true;
    }
};
/*
因為只由小寫字母組成，因此用 array[26]便能計算完畢
將兩個字串中的字母進行數量計算，計算之後如果alphacount裡面有大於0的數
代表兩個字串不是相同字母異序詞(anagram)
*/