class Solution
{
public:
    bool checkTwoChessboards(string coordinate1, string coordinate2)
    {
        int one = coordinate1[0] + coordinate1[1];
        int two = coordinate2[0] + coordinate2[1];

        return one % 2 == two % 2;
    }
};