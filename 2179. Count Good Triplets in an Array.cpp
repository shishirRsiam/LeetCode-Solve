class Solution {
public:
    long querySegmentTree(int queryStart, int queryEnd, int i, int l, int r, vector<long>& segmentTree)
    {
        if(l > queryEnd or r < queryStart) return 0;
        if(l >= queryStart and r <= queryEnd) return segmentTree[i];
        
        int mid = l + (r - l) / 2;
        long left = querySegmentTree(queryStart, queryEnd, 2 * i + 1, l, mid, segmentTree);
        long right = querySegmentTree(queryStart, queryEnd, 2 * i + 2, mid + 1, r, segmentTree);
        return left + right;
    }
    void updateSegmentTree(int i, int l, int r, int updateIndex, vector<long>& segmentTree)
    {
        if(l == r) 
        {
            segmentTree[i] = 1;
            return;
        }

        int mid = l + (r - l) / 2;
        if(updateIndex <= mid) updateSegmentTree(2 * i + 1, l, mid, updateIndex, segmentTree);
        else updateSegmentTree(2 * i + 2, mid + 1, r, updateIndex, segmentTree);
        segmentTree[i] = segmentTree[2 * i + 1] + segmentTree[2 * i + 2];
    }
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) 
    {
        int n = nums1.size();
        unordered_map<int, int> index;
        for(int i = 0; i < n; i++)
            index[nums2[i]] = i;

        long ans = 0;
        vector<long> segmentTree(4 * n);
        updateSegmentTree(0, 0, n - 1, index[nums1[0]], segmentTree);
        for(int i = 1; i < n; i++)
        {
            int idx = index[nums1[i]];
            long leftCommonCount = querySegmentTree(0, idx, 0, 0, n - 1, segmentTree);
            long leftNotCommonCount = i - leftCommonCount;

            long elementsAfterIdxNums2 = (n - 1) - idx;
            long rightCommonCount = elementsAfterIdxNums2 - leftNotCommonCount;

            ans += leftCommonCount * rightCommonCount;

            updateSegmentTree(0, 0, n - 1, idx, segmentTree);
        }
        return ans;
    }
};