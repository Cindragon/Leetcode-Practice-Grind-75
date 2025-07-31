class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> curr;    // 儲存以當前元素結尾的所有子陣列的 OR 結果
        unordered_set<int> res;     // 儲存所有出現過的 OR 結果（用來去重）
        for(const auto&n:arr){
            unordered_set<int> next;
            next.insert(n);
            for(const auto&i:curr){
                next.insert(i|n);
            }
            curr=next;
            res.insert(curr.begin(), curr.end());
        }
        return res.size();
    }
};

/*
- curr 儲存的是以「前一個數結尾的所有子陣列 OR 結果」
- 每個新數字 n 加入後，可以與 curr 中的每個結果做 OR，得到新的結果
- 這些新的 OR 結果代表所有「以 n 結尾」的子陣列
- 每輪把這些結果加入 res（總結果集合）
- 最後回傳 res 的大小（代表不同 OR 值的數量）
*/