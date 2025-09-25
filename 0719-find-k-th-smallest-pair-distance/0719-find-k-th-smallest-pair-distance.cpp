class Solution {
private:
    bool canFind(const vector<int>&nums, int k, int target){
        int count=0;
        int left=0;
        for(int right=0;right<nums.size();++right){
            while(nums[right]-nums[left]>target){
                ++left;
            }
            count+=(right-left);
            if(count>=k)    return true;
        }
        return count>=k;
    }
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        int left=0;
        int right=nums[n-1]-nums[0];
        while(left<=right){
            int mid=left+(right-left)/2;
            if(canFind(nums, k, mid)){
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        return left;
    }
};
/*
這幾題 410、1101、875、719 都是很相似的二元搜尋模板題
要找到第 k 個最小的距離，我們需要找到左右邊界
1. 先將 nums 進行排序，left=0，right=nums[n-1]-nums[0](最大減最小)
2. 在 left<=right 的情況下找中位數，
   - 用 canFind 判斷「距離 ≤ mid 的數量是否 ≥ k」
       - true → mid 可行，可能還能找更小 → right = mid - 1
       - false → mid 不可行 → left = mid + 1

3. canFind 函式：
   - 用雙指標 sliding window 計算距離 ≤ target 的對數
   - 遍歷右指標 right，左指標 left 移動，count += (right - left)
   - 如果 count ≥ k → 已經夠 k 對，直接回傳 true

4. 最終答案：
   - left 最終停在「第 k 個最小距離」，直接 return left
*/