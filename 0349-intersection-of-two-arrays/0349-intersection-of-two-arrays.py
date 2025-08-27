class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        table={} 
        for num in nums1:
            table[num]=table.get(num, 0)+1
        
        res=set()
        for num in nums2:
            if num in table:
                res.add(num) #找到交集元素
                del table[num] #確保每個元素只加入一次
        return list(res)

'''
用字典來儲存nums1裡面的元素跟出現次數，最後用set來儲存有交集的元素以避免重複
並且在最後將set轉成list
'''