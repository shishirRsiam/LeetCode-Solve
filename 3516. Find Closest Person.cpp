class Solution {
public:
    int findClosest(int x, int y, int z) 
    {
        int dif = abs(z - x) - abs(z - y);  
        if(dif) return dif < 0 ? 1 : 2;  
        return 0; 
    }
};