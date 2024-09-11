class Solution
{
public:
    int minFlips(int a, int b, int c)
    {
        // Initialize a variable 'ans' to count the number of flips required.
        int ans = 0;

        // Create bitsets for a, b, and c to represent their binary form.
        // Each bitset is 32 bits long, as integers are represented in 32 bits.
        bitset<32> A(a), B(b), C(c);

        // Iterate over each bit position from 0 to 31.
        for (int i = 0; i < 32; i++)
        {
            // Check if the bitwise OR of A and B differs from C at the current bit position.
            // (A[i] or B[i]) != C[i] checks if the combined bits of A and B do not match C.
            if ((A[i] || B[i]) != C[i])
            {
                // If C[i] is 0, we need to flip both A[i] and B[i] (if they are 1) to achieve 0.
                // Thus, we add the sum of A[i] and B[i] to 'ans'.
                if (!C[i])
                    ans += A[i] + B[i];
                // If C[i] is 1, we need to flip either A[i] or B[i] (whichever is 0) to achieve 1.
                // Hence, we increment 'ans' by 1.
                else
                    ans += 1;
            }
        }

        // Return the total number of flips required to convert A and B into C.
        return ans;
    }
};
