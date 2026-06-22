class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> mp;
        for(const auto&c:text){
            mp[c]++;
        }
        return min({
            mp['b'],
            mp['a'],
            mp['l']/2,
            mp['o']/2,
            mp['n']
        });
    }
};

/*
找到組成字母裡面最少的那個字母並回傳其數值
*/