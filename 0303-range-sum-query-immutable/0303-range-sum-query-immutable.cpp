class NumArray {
private:
    vector<int> segTree;
    int n;
    void buildTree(vector<int>&nums, int idx, int l, int r){
        if(l==r){
            segTree[idx]=nums[l];
            return;
        }
        int mid=l+(r-l)/2;
        buildTree(nums, idx*2+1 ,l, mid);
        buildTree(nums, idx*2+2, mid+1, r);
        segTree[idx]=segTree[idx*2+1]+segTree[idx*2+2];
    }
    int queryRange(int idx, int l, int r, int ql, int qr){
        if(qr<l || ql>r)    return 0;
        if(ql<=l && r<=qr)  return segTree[idx];
        int mid=l+(r-l)/2;
        return queryRange(idx*2+1, l, mid, ql, qr)
               +queryRange(idx*2+2, mid+1, r, ql, qr);
    }
public:
    NumArray(vector<int>& nums) {
        n=nums.size();
        if(n==0)    return;
        segTree.resize(4*n);
        buildTree(nums, 0, 0, n-1);
    }
    
    int sumRange(int left, int right) {
        return queryRange(0, 0, n-1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */