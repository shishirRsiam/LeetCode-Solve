class Solution {
public:
    bool isPowerOfFour(int n)
    {
        if (n == 0)
        {
            return false;
        }

        return (ceil(log(n) / log(4)) == floor(log(n) / log(4)));
    }
};

class Solution {
public:
    bool isPowerOfFour(int n)
    {
        if (n == 0)
        {
            return false;
        }

        return (ceil(log(n) / log(4)) == floor(log(n) / log(4)));
    }
};

class Solution {
public:
    bool isPowerOfFour(int n)
    {
        if (n == 0)
        {
            return false;
        }
        while (n % 4 == 0)
        {
            n /= 4;
        }
        return n == 1;
    }
};