class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> minFreq(26, INT_MAX); //計算各個字母最少出現幾次
        for(const auto&word:words){
            vector<int> wordCount(26, 0);
            for(const auto&c:word){
                wordCount[c-'a']++;
            }
            for(int i=0;i<26;i++){
                minFreq[i]=min(minFreq[i], wordCount[i]);
            }
        }
        vector<string> res;
        for(int i=0;i<26;i++){
            for(int j=0;j<minFreq[i];j++){
                res.push_back(string(1, 'a'+i));
            }
        }
        return res;
    }
};

/*
這題要計算所有共同出現的字母並且可以重複
先用 minFreq 來計算各個字母最少出現的次數，並且遍歷整個 words 陣列
將words裡面的每個字母數量進行計算，對所有單字取最小值，就是共同出現的次數
最後將計算出來的結果轉換成string回傳
*/