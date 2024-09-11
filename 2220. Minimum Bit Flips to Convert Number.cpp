class Solution
{
public:
    int minBitFlips(int start, int goal)
    {
        // Convert the 'start' and 'goal' integers into 32-bit binary representation using bitset
        bitset<32> startBit(start), goalBit(goal);

        // Initialize a variable 'ans' to store the number of bit flips needed
        int ans = 0;

        // Loop through each bit from 0 to 31 (since we are dealing with 32-bit integers)
        for (int i = 0; i < 32; i++)
            // If the bit at position 'i' in startBit is different from the bit in goalBit, increment 'ans'
            if (startBit[i] != goalBit[i])
                ans += 1;

        // Return the total number of bit flips needed
        return ans;
    }
};