class Solution {
private:
    int binary(vector<int>&potions, long long& need, int& length){
        int left=0, right=length;
        while(left<right){
            int mid=left+(right-left)/2;
            if(potions[mid]>=need){
                right=mid;
            }
            else{
                left=mid+1;
            }
        }
        return length-left;
    }
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> ans;
        sort(potions.begin(), potions.end());
        int n=spells.size(), m=potions.size();
        for(int i=0;i<n;++i){
            long long need=(success+spells[i]-1)/spells[i];
            ans.push_back(binary(potions, need, m));
        }
        return ans;
    }
};

/*
如果要找到至少大於等於 success 的威力，可以透過向上取整的方式來進行比較
先將藥水進行排序(以方便二元搜索)
接著求出所需要的 need =(success+spells[i]-1)/spells[i])
並且將其變數代入 binary search 的函式
在函式中：
    left=0, right=position.size()(length)
    在 left<right 時，mid=left+(right-left)/2
    如果 need>=potions[mid] right=mid(往左找看看有沒有更多)
    反之則 left=mid+1(往右找看有沒有超過)
    最後回傳 length-left(有多少個藥水超過標準)
*/