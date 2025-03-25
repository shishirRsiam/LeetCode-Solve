class Solution
{
public:
    int maxContainers(int n, int w, int maxWeight)
    {
        n *= n;
        if (n * w <= maxWeight)
            return n;
        return maxWeight / w;
    }
};