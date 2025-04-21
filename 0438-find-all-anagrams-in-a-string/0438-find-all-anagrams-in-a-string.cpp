class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans={};
        if(p.size()>s.size()) return ans;
        vector<int> p_count(26), s_count(26);
        for(const auto&c:p){
            p_count[c-'a']++;
        }
        for(int i=0;i<p.size();i++){
            s_count[s[i]-'a']++;
        }
        if(s_count==p_count) ans.push_back(0);
        for(int i=p.size();i<s.size();i++){
            s_count[s[i-p.size()]-'a']--;
            s_count[s[i]-'a']++;
            if(s_count==p_count){
                ans.push_back(i-p.size()+1);
            }
        }
        return ans;
    }
};