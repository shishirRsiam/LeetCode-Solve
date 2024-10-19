class Solution {
public:
    char findKthBit(int n, int k) 
    {
        string bits = "0";
        for(int _ = 1; _ < n; _++)
        {
            string newBits = "1";
            int size = bits.size();
            for(int i = size - 1; i >= 0; i--)
                newBits += (bits[i] == '0' ? '1' : '0');
            bits += newBits;
        }
        return bits[k - 1];
    }
};