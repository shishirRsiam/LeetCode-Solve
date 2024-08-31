class Solution {
public:
    // Function to generate a hashed string from the input string 's' using integer 'k'
    string stringHash(string s, int k) 
    {
        string ans; // Initialize an empty string to store the resulting hash
        int i = 0, n = s.size(); // 'i' is the index iterator, 'n' is the length of the input string 's'
        
        // Iterate through the entire string
        while(i < n)
        {
            int sum = 0; // Variable to store the cumulative sum of ASCII values of 'k' characters
            int temp = k; // 'temp' is a temporary variable to keep track of the number of characters to sum

            // Loop to sum the ASCII values of the next 'k' characters
            while(temp--)
                sum += s[i++] - 'a'; // Convert character to an integer (0 for 'a', 1 for 'b', etc.) and add to sum
            
            // Calculate the index by taking modulo 26 twice, ensuring it wraps within the alphabet
            int idx = (sum % 26) % 26; 

            // Convert the index back to a character and append it to the result string 'ans'
            ans += idx + 'a';
        }

        // Return the final hashed string
        return ans;
    }
};