class Solution {
public:

    void swapChar(vector<char> &vec)
    {
        int n = vec.size();
        int Hash = 0;
        unordered_map<int, int>store;
        for(int i = 0; i < n; i++)
        {
            Hash += vec[i] == '#';
            if(vec[i] == '*')
            {
                store[i] = Hash;
                Hash = 0;
            }
        }
        if(Hash) store[n] = Hash;
        for(auto [idx_i, count] : store)
        {
            int idx = idx_i;
            // cout<<idx<<" "<<count<<endl;
            while(count--)
            {
                idx--;
                vec[idx] = '#';
                // cout<<idx<<" ";
            }
            while(idx)
            {
                idx--;
                if(vec[idx] == '*') break;
                vec[idx] = '.';
                // cout<<idx<<" ";
            }
        }
        // for(auto val:vec) cout<<val<<" ";
        // cout<<endl;
    }

    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) 
    {
        int n = box.size(), m = box[0].size();

        for(int i = 0; i < n; i++)
        {
            swapChar(box[i]);
            for(int j = 0; j < m; j++)
            {

            }
        }

        vector<vector<char>>box90;
        for(int i = m - 1; i >= 0; i--)
        {
            vector<char>temp;
            for(int j = n - 1; j >= 0; j--)
            {
                temp.push_back(box[j][i]);
                // cout<<i<<":"<<j<<" ";
            }
            // cout<<endl;
            box90.push_back(temp);
        }

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                // cout<<box90[i][j]<<" ";
            }
            // cout<<endl;
        }
        reverse(begin(box90), end(box90));
        return box90;
    }
};