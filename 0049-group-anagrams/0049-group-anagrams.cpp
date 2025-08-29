class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> res;
        for(const auto&str:strs){
            string sortedS=str;
            sort(sortedS.begin(), sortedS.end());
            res[sortedS].push_back(str);
        }
        vector<vector<string>> result;
        for(const auto&pair:res){
            result.push_back(pair.second);
        }
        return result;
    }
};

/*
用map來儲存已經分類過的字串
在遍歷字串陣列的時候，將字串的字母進行排序，用排序後字串當 key 分組
最後將分類好的字串push_back到result並且回傳
*/