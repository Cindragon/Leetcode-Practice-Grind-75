class Solution {
public:
    string largestGoodInteger(string num) {
        string ans="";
        string temp;
        for(int i=0;i<=num.size()-3;i++){
            if(num[i]==num[i+1]&&num[i]==num[i+2]){
                temp=num.substr(i, 3);
                if(temp>ans){
                    ans=temp;
                }
            }
        }
        return ans;
    }
};

/*
用 substr 的方式來儲存子字串
並且與空字串比較，如果比較大就直接取代 ans 
*/