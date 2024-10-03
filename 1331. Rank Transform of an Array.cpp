class Solution
{
public:
    vector<int> arrayRankTransform(vector<int> &arr)
    {
        set<int> st(begin(arr), end(arr));

        int rankNumber = 1;
        unordered_map<int, int> rank;
        for (auto val : st)
            rank[val] = rankNumber++;

        for (auto &val : arr)
            val = rank[val];
        return arr;
    }
};