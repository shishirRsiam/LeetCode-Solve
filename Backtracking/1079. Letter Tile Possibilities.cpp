class Solution {
    public:
        unordered_set<string> store;
        void backtrack(string &tiles, string cur, int idx)
        {
            store.insert(cur);
            if(idx == tiles.size()) return;
            for(int i = idx; i < tiles.size(); i++)
                backtrack(tiles, cur + tiles[i], i + 1);
        }
    
        unordered_set<string> all_permutation;
        void permutation(string &tiles, int idx)
        {
            all_permutation.insert(tiles);
            for(int i = idx; i < tiles.size(); i++)
            {
                swap(tiles[i], tiles[idx]);
                permutation(tiles, idx + 1);
                swap(tiles[i], tiles[idx]);
            }
        }
    
        int numTilePossibilities(string tiles) 
        {
            permutation(tiles, 0);
            for(auto s : all_permutation) 
                backtrack(s, "", 0);
            return store.size() - 1;
        }
    };