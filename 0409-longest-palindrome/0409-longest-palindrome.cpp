class Solution {
public:
    int longestPalindrome(string s) {
        int count=0;
        bool check=0;
        unordered_map<char, int> mpp;
        for(const auto&c:s){
            mpp[c]++;
        }
        auto iter=mpp.begin();
        while(iter!=mpp.end()){
            int n=iter->second;
            if(n%2==0) count+=n;
            else{
                count=count+n-1;
                check=1;
            }
            iter++;
        }
        if(check==1) count++;
        return count;
    }
};

/*
用 map 來儲存原本字串裡的字母有幾個

遍歷 map：
- 如果某字母出現偶數次，代表它可以完整對稱地放進回文中，直接加上
- 如果某字母出現奇數次，則取 (次數 - 1)，留下 1 個字元作為可能的中間字符
- 最後，如果有至少一個奇數次的字母，代表可以在中間放一個字符，使回文長度再加 1

*/