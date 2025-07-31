class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res(nums1.size(), -1);
        stack<int> st;
        unordered_map<int, int> unmap1;
        for(int i=0;i<nums1.size();i++){
            unmap1[nums1[i]]=i;
        }
        st.push(0);
        for(int i=1;i<nums2.size();i++){
            while(!st.empty()&&nums2[i]>nums2[st.top()]){
                if(unmap1.count(nums2[st.top()])){  //找這個元素是不是有在nums1中出現
                    int index=unmap1[nums2[st.top()]];  //這個元素在nums1的哪個位置
                    res[index]=nums2[i];    //比這個元素還要大的元素nums2[i]
                }
                st.pop();
            }
            st.push(i);
        }
        return res;
    }
};

/*
此題同樣可以用單調棧的方式來處理
先透過 unordered_map 對 nums1 的元素做映射(儲存索引值)
res 空間大小與 nums1 相同，初始值為 -1
接著一樣先將 nums2 的第一個索引值 push 進 stack 開始比較
在 stack 不為空且 nums2[i]>nums2[st.top()] 時
若是在 map 中找到 nums2[st.top()]的值(在 nums1 中有出現)
透過 index 記錄此元素的索引值，並且將 res[index] 賦值為 nums2[i]
最後回傳 res
*/