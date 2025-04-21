class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans={};
        if(p.size()>s.size()) return ans;
        vector<int> p_Count(26), s_Count(26);
        for(const auto&c:p){
            p_Count[c-'a']++;
        }
        for(int i=0;i<p.size();i++){
            s_Count[s[i]-'a']++;
        }
        if(s_Count==p_Count) ans.push_back(0);
        for(int i=p.size();i<s.size();i++){
            s_Count[s[i-p.size()]-'a']--;
            s_Count[s[i]-'a']++;
            if(s_Count==p_Count){
                ans.push_back(i-p.size()+1);
            }
        }
        return ans;
    }
};

/*
用 hash 表的方式儲存每個字母在 p 字串出現的次數(p_Count)
接著用 p 的長度儲存 s 字串 p.size() 個字母(s_Count)
如果 s_Count==p_Count，push_back(0)(代表從 0 開始有Anagram)
接著用滑動窗口的方式，從 p.size() 的位置開始遊歷 s字串
s_count[s[i-p.size()]-'a']--(將滑出視窗的左邊字母從頻率統計中移除)
s_count[s[i]-'a']++;(再繼續向後移動，將新加入右邊的字母加入到頻率統計中)
如果相等就push_back(i-p.size()+1(新 Anagram 的起始位置))
*/