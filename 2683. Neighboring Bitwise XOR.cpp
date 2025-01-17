class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) 
    {
        int count = 0;
        for(int &bit : derived) count += bit;
        return count % 2 == 0;    
    }
};