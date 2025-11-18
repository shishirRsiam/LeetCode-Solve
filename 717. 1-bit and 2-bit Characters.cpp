class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) 
    {
        int isOneBit = 1, i = 0, n = bits.size();
        while(i < n) 
        {
            if(bits[i]) 
            {
                isOneBit = 0;
                i += 1;
            }
            else isOneBit = 1;
            i += 1;
        }   
        return isOneBit; 
    }
};