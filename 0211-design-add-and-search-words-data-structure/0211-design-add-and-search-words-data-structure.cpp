class TrieNode{
public:
    TrieNode* children[26];
    bool isEnd;
    TrieNode():isEnd(false){
        for(int i=0;i<26;++i){
            children[i]=nullptr;
        }
    }
};

class WordDictionary {
private:
    TrieNode* root;
    bool dfs(string& word, int index, TrieNode* node){
        if(!node)   return false;
        if(index==word.size())    return node->isEnd;
        char c=word[index];
        if(c=='.'){
            for(int i=0;i<26;++i){
                if(dfs(word, index+1, node->children[i]))   return true;
            }
            return false;
        }
        else{
            int nextIdx=c-'a';
            return dfs(word, index+1, node->children[nextIdx]);
        }
    }
public:
    WordDictionary() {
        root=new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* node=root;
        for(const auto&c:word){
            int idx=c-'a';
            if(!node->children[idx]){
                node->children[idx]=new TrieNode();
            }
            node=node->children[idx];
        }
        node->isEnd=true;
    }
    
    bool search(string word) {
        return dfs(word, 0, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

 /*
 這題一樣用到 LeetCode 208 設計 Trie 的技巧
 首先也要先建構一個 Trie 樹，addWord 的部分跟 208 一模一樣
 但是在 search 中，因為會有字母被 '.' 被取代的問題，所以我們要用 dfs 遞迴的手法來進行搜尋
 首先要傳入要搜尋的字串，起始位置以及 Trie 樹的 root
 終止條件：
    如果 node 為空(代表沒有這個字)，回傳 false
    如果 index==word.size()(字串結尾)，回傳 node->isEnd()
    字母 c 為當前要找的字母，這邊分成兩條路：
    如果 c=='.'，那我們就要用 dfs 遍歷當前節點的路徑，一旦找到 true 代表有這個字(不管取代幾個字母)
    如果 c 是普通字母，那麼就一樣沿著當前字母的路徑搜尋。
    遇到普通字母 → 往對應子節點遞迴。
    遇到 . → 嘗試所有 26 個子節點（DFS/backtracking）。
    到達字串末尾 → 看 isEnd 是否為 true。
 */