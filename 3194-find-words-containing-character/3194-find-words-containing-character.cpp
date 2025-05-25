class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> res;
        for(int i=0;i<words.size();i++){
            bool flag=0;
            for(const auto&c:words[i]){
                if(c==x){
                    flag=1;
                    res.push_back(i);
                    break;
                }
            }
        }
        return res;
    }
};