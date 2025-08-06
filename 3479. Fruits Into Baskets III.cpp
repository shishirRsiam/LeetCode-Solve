class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) 
    {
        int unplaced = 0, n = fruits.size();

        vector<int> SegmentTree(n * 4, -1);
        buildSegmentTree(0, 0, n - 1, baskets, SegmentTree);
        for(const int &fruit : fruits)
            unplaced += not placedSegmentTree(0, 0, n - 1, fruit, SegmentTree);
        return unplaced;
    }
    void buildSegmentTree(int i, int left, int right, vector<int>& baskets, vector<int> &SegmentTree)
    {
        if(left == right)
        {
            SegmentTree[i] = baskets[left];
            return;
        }

        int mid = (left + right) / 2;
        int left_i = i * 2 + 1, right_i = left_i + 1;
        buildSegmentTree(left_i, left, mid, baskets, SegmentTree);
        buildSegmentTree(right_i, mid + 1, right, baskets, SegmentTree);

        SegmentTree[i] = max(SegmentTree[left_i], SegmentTree[right_i]);
    }
    bool placedSegmentTree(int i, int left, int right, int val, vector<int> &SegmentTree)
    {
        if(SegmentTree[i] < val) return false;
        if(left == right)
        {
            SegmentTree[i] = -1;
            return true;
        }

        bool placed = false;
        int mid = (left + right) / 2;
        int left_i = i * 2 + 1, right_i = left_i + 1;
        if (val <= SegmentTree[left_i])
            placed = placedSegmentTree(left_i, left, mid, val, SegmentTree);
        else 
            placed = placedSegmentTree(right_i, mid + 1, right, val, SegmentTree);

        SegmentTree[i] = max(SegmentTree[left_i], SegmentTree[right_i]);

        return placed;
    }
};