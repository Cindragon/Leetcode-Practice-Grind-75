class Solution {
public:
    vector<int> partitionLabels(string s) {
        int hash[27]={0};
        for(int i=0;i<s.size();i++){
            hash[s[i]-'a']=i;   //記錄每個字母在s字串中出現的最遠位置
        }
        vector<int> res;
        int left=0, right=0;    //記錄左右區間的大小
        for(int i=0;i<s.size();i++){
            right=max(right, hash[s[i]-'a']);   //找到右邊界的最大值
            if(i==right){
                res.push_back(right-left+1);
                left=right+1;
            }
        }
        return res;
    }
};

/*
使用貪心算法，找到每個字母出現的最遠的位置
先用一個哈希表進行記錄，將每個字母出現的最遠位置記下來
接下來設定左右邊界，再遍歷一次 s 字串
一直遍歷找到右邊界的最大值，一旦 i 遍歷到right(最遠的邊界)
計算長度的之後同時更新left邊界
*/