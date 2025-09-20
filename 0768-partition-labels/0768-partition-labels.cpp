class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> last(26, 0);
        for(int i=0;i<s.size();i++){
            last[s[i]-'a']=i;
        }
        vector<int> ans;
        int start=0, end=0;
        for(int i=0;i<s.size();i++){
            end=max(end, last[s[i] - 'a']);
            if(i==end){
                ans.push_back(end-start+1);
                start=i+1;
            }
        }
        return ans;
    }
};

/*
這題可以用 greedy 的方式來解題
1. 用 last 陣列來儲存各個字母最後出現的位置
2. 用 start 跟 end 來表示每個陣列出現的開始跟結束位置，接著再次遍歷 s 字串
先找到首字母的最後出現的位置更新為 end ，若是 i==end 代表這邊會是一個區間
將區間長度儲存後，接著更新 start 的值，最後回傳 ans
*/