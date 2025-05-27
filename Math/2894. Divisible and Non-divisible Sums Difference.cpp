class Solution {
public:
    int differenceOfSums(int n, int m) 
    {
        int sum1 = 0, sum2 = 0;
        for(int num = 1; num <= n; num++)
            num % m ? sum1 += num : sum2 += num;
        return sum1 - sum2;
    }
};