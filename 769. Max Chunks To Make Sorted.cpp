class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) 
    {
        int Chunks = 0, seen = 0, n = arr.size();
        for(int i = 0; i < n; i++)
        {
            seen = max(seen, arr[i]);
            if(seen == i) Chunks += 1;
        }
        return Chunks;
    }
};