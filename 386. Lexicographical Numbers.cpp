class Solution
{
public:
    vector<int> lexicalOrder(int n)
    {
        int num = 1;
        vector<int> ans;
        while (ans.size() < n)
        {
            ans.push_back(num);
            // Try to go deeper by multiplying by 10
            if (num * 10 <= n)
                num *= 10;

            // If num + 1 is valid and does not end in a zero, increment num
            else
            {
                if (num >= n)
                    num /= 10; // Backtrack to parent
                num += 1;
                // While num ends in 0, we need to backtrack by dividing by 10
                while (num % 10 == 0)
                    num /= 10;
            }
        }
        return ans;
    }
};

class Solution
{
public:
    vector<int> lexicalOrder(int n)
    {
        // Initialize an empty vector to store the result in lexicographical order
        vector<int> ans;
        // Start with the first number, which is 1
        int number = 1;

        // Loop until we've added 'n' numbers to the result vector
        while (ans.size() < n)
        {
            // Add the current number to the result vector
            ans.push_back(number);

            // Case 1: If multiplying the current number by 10 doesn't exceed 'n', go deeper
            // This moves to the next level in lexicographical order (e.g., 1 -> 10 -> 100)
            if (number * 10 <= n)
                number *= 10;

            // Case 2: If the current number can be incremented and it doesn't end in 9, increment it
            // This moves to the next number in sequence, but stays at the same level (e.g., 1 -> 2 -> 3)
            else if (number + 1 <= n && number % 10 != 9)
                number += 1;

            // Case 3: Backtrack if the number ends in 9 or cannot be incremented further within 'n'
            else
            {
                // Remove trailing 9's by dividing by 10 until the last digit is no longer 9
                // This step moves up one level in lexicographical order (e.g., 19 -> 1, 29 -> 2)
                while ((number / 10) % 10 == 9)
                    number /= 10;

                // Move up to the next valid number in lexicographical order
                // This handles numbers like moving from 19 -> 2, 99 -> 10, etc.
                number = number / 10 + 1;
            }
        }

        // Return the vector with numbers in lexicographical order
        return ans;
    }
};

// for explain using ChatGPT.