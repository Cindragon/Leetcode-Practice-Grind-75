class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> mp1;
        for(const auto&c:magazine){
            mp1[c]++;
        }
        for(const auto&c:ransomNote){
            if(mp1[c]<=0) return false;
            mp1[c]--;
        }
        return true;
    }
};

/*
用map來解決這題mp1
遍歷magazine字串的所有字母並統計字母數量
接著遍歷ramsomNote字串
如果mp1中的字母數量小於等於0
說明字母數量不夠 return false
如果不是就return true
*/