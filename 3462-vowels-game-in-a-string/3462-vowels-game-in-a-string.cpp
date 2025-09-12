class Solution {
public:
    bool doesAliceWin(string s) {
        for(const auto&c:s){
            if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u')  return true;
            
        }
        return false;
    }
};

/*
只要找到字串中有一個以上的母音就是 Alice 贏了
因為如果沒有母音，代表只有 Bob 可以先行動，能把整個字串刪除
相反的，不管有幾個母音，Alice 都可以將其刪到剩下奇數個母音或是全部刪除
因此判斷條件相對簡單
*/